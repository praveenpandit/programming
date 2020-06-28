#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isValid(string str, string check)
{
    if (str.length() == 0 && check.length() == 0)
        return true;

    int num = 0;
    int digits = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (digits > 0 && (str[i] < '0' || str[i] > '9'))
            break;
        if (str[i] >= '0' && str[i] <= '9')
        {
            num = num * 10 + str[i] - '0';
            digits++;
        }
    }
    if (str[0] == check[0] && str[digits + 1] == check[num + 1])
        return true && isValid(str.substr(digits + 2), check.substr(num + 2));
    else
        return false;
}
int main()
{
    cout << isValid("i18n", "internationalization") << endl;
    cout << isValid("f2eb2k", "foiebaak") << endl;
    cout << isValid("f6k", "feedback") << endl;
    return 0;
}