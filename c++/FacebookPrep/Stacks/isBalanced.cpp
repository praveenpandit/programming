#include <iostream>
#include <string>
#include <stack>

using namespace std;
bool isBalanced_rec(string s, char ch = 's')
{
    if (s.size() == 0)
        return true;
    if (ch == '(' && s[0] == ')')
        return true;
    else if (ch == '{' && s[0] == '}')
        return true;
    else if (ch == '[' && s[0] == ']')
        return true;
    else if (s[0] == '(' || s[0] == '{' || s[0] == '[')
        return isBalanced_rec(s.substr(1), s[0]);
    else
        return false;
}
// bool isBalanced_rec(string s)
// {
//     char ch;
//     bool flag = false;
//     // if (s.size() == 0)
//     //     flag = true;
//     // if (ch == '(' && s[0] == ')')
//     //     flag = true;
//     // else if (ch == '{' && s[0] == '}')
//     //     flag = true;
//     // else if (ch == '[' && s[0] == ']')
//     //     flag = true;
//     // else
//     //     flag = false;
//     if (s[0] == '(' || s[0] == '{' || s[0] == '[')
//         return isBalanced_rec(s.substr(1));
//     else
//         ch = s[0];
// }
bool isBalanced(string s)
{
    return isBalanced_rec(s);
}
bool isBalanced_itr(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '(' || i == '{' || i == '[')
            st.push(i);
        else
        {
            bool flag = false;
            char ch = st.top();
            st.pop();
            switch (ch)
            {
            case '[':
                if (i == ']')
                    flag = true;
                break;
            case '{':
                if (i == '}')
                    flag = true;
                break;
            case '(':
                if (i == ')')
                    flag = true;
                break;
            default:
                flag = false;
                break;
            }
            if (!flag)
                return false;
        }
    }
    return true;
}
int main()
{
    // cout << isBalanced_itr("({[{}])") << endl;
    cout << isBalanced("()") << endl;
    return 0;
}