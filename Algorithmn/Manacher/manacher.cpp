#include <iostream>
#include <string>
#include <vector>
// https://www.cnblogs.com/fan1-happy/p/11166182.html
using namespace std;

int Manacher(string& input)
{
    if (input.empty()) {
        return 0;
    }
    // Add '#'
    string newString = "#";
    for (char word : input) {
        newString += word;
        newString += '#';
    }
    int maxRight = 0;
    int maxMid = 0;
    int maxLength = 0;
    vector<int> maxRadius(newString.size(), 1);
    for (int i = 1; i < newString.size(); i++) {
        if (i < maxRight) {
            maxRadius[i] = min(maxRadius[2 * maxMid - i], maxRight - i);
        }
        while (newString[i - maxRadius[i]] == newString[i + maxRadius[i]]) {
            maxRadius[i]++;
        }
        if (maxRight < i + maxRadius[i]) {
            maxMid = i;
            maxRight = i + maxRadius[i];
        }
        maxLength = max(maxLength, maxRadius[i] - 1);
    }
    return maxLength;
}
int main()
{
    string input = "abcbbabbc";
    cout << Manacher(input) << endl;
    return 0;
}