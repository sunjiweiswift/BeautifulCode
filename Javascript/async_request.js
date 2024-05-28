function concurrentRequest(urls, maxNum) {
  const pending = []; // 存储正在进行的请求
  const results = []; // 存储请求结果

  return new Promise((resolve, reject) => {
    function next() {
      if (pending.length < maxNum && urls.length > 0) {
        const url = urls.shift();

        fetch(url)
          .then(response => response.json())
          .then(data => {
            results.push(data);
            pending.splice(pending.indexOf(url), 1);
            next();

            if (urls.length === 0 && pending.length === 0) {
              resolve(results);
            }
          })
          .catch(error => {
            reject(error);
          });

        pending.push(url);
      }
    }

    while (urls.length > 0) {
      next();
    }
  });
}

// 示例用法
const urls = [
  'https://jsonplaceholder.typicode.com/todos/1',
  'https://jsonplaceholder.typicode.com/todos/2',
  'https://jsonplaceholder.typicode.com/todos/3',
];

const maxNum = 2; // 最大并发数为 2

concurrentRequest(urls, maxNum)
  .then(results => console.log(results))
  .catch(error => console.error(error));
