#include <iostream>
#include <string>

using namespace std;

int Manacher(string& input)
{
    // Add '#'
    string newString = "#";
    for (char word : input) {
        newString += word;
        newString += '#';
    }
    int rightMax = 0;
    int midMax = 0;
    for (int i = 1; i < newString.size(); i++) {

    }
}
int main()
{
    string input = "abbababa";
    cout << Manacher(input) << endl;
    return 0;
}