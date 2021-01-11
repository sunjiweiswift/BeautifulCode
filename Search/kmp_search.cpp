#include <cstring>
#include <iostream>
#include <string>
// int KmpSearch(char* s, char* p)
// {
//     int i = 0;
//     int j = 0;
//     int sLen = strlen(s);
//     int pLen = strlen(p);
//     while (i < sLen && j < pLen) {
//         //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
//         if (j == -1 || s[i] == p[j]) {
//             i++;
//             j++;
//         } else {
//             //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
//             //next[j]即为j所对应的next值
//             j = next[j];
//         }
//     }

//     if (j == pLen)
//         return i - j;
//     else
//         return -1;
// }
int main() {
    const char* s = "hello, huawei";
    const char* p = "huawei";
    // std::cout << KmpSearch(s, p) << std::endl;
}