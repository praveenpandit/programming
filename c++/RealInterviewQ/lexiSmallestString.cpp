#include <iostream>
#include <string>
using namespace std;
/* void lexiSmallestString(string &str)
{
    for (int i = str.length() - 2; i >= 0; i--)
    {
        if (str[i] > str[i + 1])
        {
            str.erase(str.begin() + i);
            break;
        }
    }
} */
void lexiSmallestString(string &str, int i)
{
    if (i)
    {
        if (str[i] > str[i + 1])
            str.erase(str.begin() + i);
        else
            lexiSmallestString(str, i - 1);
    }
}
int main()
{
    string s = "abcxd";
    // cout << s[s.length() - 1];
    // lexiSmallestString(s);
    lexiSmallestString(s, s.length() - 2);
    cout << s;
}