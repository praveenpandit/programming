#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int validSubString(char *str, char ch, int idx, int n, int *i)
// {
//     if (*str)
//     {
//         if (n == 0 && *str == ch)
//         {
//             *i = idx - 1;
//             validSubString(str - 1, *(str - 1), idx - 1, 2, i);
//         }
//         else if (n == 0 && *str != ch)
//             validSubString(str + 1, *str, idx + 1, 2, i);
//         else if (*str == ch)
//             validSubString(str + 1, *str, idx + 1, n - 1, i);
//     }
//     return *i;
// }

/* vector<int> validSubString(string &str)
{
    bool flag = false;
    vector<int> ret{0};
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i - 1] == str[i])
        {
            if (flag)
            {
                str[i++] = '\0';
                ret.push_back(i);
                flag = false;
            }
            else
                flag = true;
        }
        else
            flag = false;
    }
    return ret;
}
 */
void validSubString(string &str, int i = 1, bool flag = false)
{
    if (str[i] != 0)
    {
        if (str[i - 1] == str[i] && !flag)
            validSubString(str, i + 1, !flag);
        else if (str[i - 1] != str[i] && flag)
            validSubString(str, i + 1, !flag);
        else if (str[i - 1] == str[i] && flag)
        {
            str[i] = '\0';
            validSubString(str, i + 2, !flag);
        }
    }
}
int main()
{
    // char s[] = "aabbaaaaabb";
    // int idx = 0;
    // cout << s + validSubString(s, s[0], 0, 2, &idx);
    string s = "aabbaabbaabbaa";
    validSubString(s);
    // vector<int> v;
    // v = validSubString(s);
    // for (auto i : v)
    //     cout << s.c_str() + i << endl;
    return 0;
}