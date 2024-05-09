function Request(urls, maxNum) {
  let successCount = 0;
  let errorCount = 0;
  const queue = urls.slice(); // 创建任务队列
  let activeCount = 0; // 当前正在进行的请求数
  let results = []; // 存储请求结果

  return new Promise((resolve, reject) => {
    function next() {
      if (queue.length === 0 && activeCount === 0) {
        resolve(results);
        console.log(`Success: ${successCount}`);
        console.log(`Errors: ${errorCount}`);
        return;
      }

      if (activeCount < maxNum) {
        const url = queue.shift();
        activeCount++;

        fetch(url)
          .then(response => response.json())
          .then(data => {
            results.push(data);
            successCount++;
            activeCount--;
            next();
          })
          .catch(error => {
            reject(error);
            activeCount--;
            errorCount++;
            next();
          });
      }
    }

    next();
  });

}

// Example usage
const urls = [
  'https://jsonplaceholder.typicode.com/posts/1',
  'https://jsonplaceholder.typicode.com/posts/2',
  'https://jsonplaceholder.typicode.com/posts/3',
  'https://jsonplaceholder.typicode.com/posts/4',
  'https://jsonplaceholder.typicode.com/posts/5',
  'https://jsonplaceholder.typicode.com/posts/6',
  'https://jsonplaceholder.typicode.com/posts/7',
];

Request(urls, 3).then(console.log);
