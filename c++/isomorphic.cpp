#include <iostream>
#include <string>
#include <map>
using namespace std;
// namespace std have been included for this problem.

// Add any helper functions(if needed) above.
/* bool is_isomorphic(string input1, string input2)
{
    char *arr = new char[256]();
    char *arr1 = new char[256]();
    string::iterator it1, it2;
    // map<char, char> s12;
    // map<char, char> s21;
    for (it1 = input1.begin(), it2 = input2.begin(); *it1 || *it2; it1++, it2++)
    {
        // s12.insert(pair<char, char>(*it1, *it2));
        // s21.insert(pair<char, char>(*it2, *it1));
        if (!arr[*it1])
            arr[*it1] = *it2;
        if (!arr[*it2])
            arr[*it2] = *it1;
        else if (arr[*it1] != *it2 || arr[*it2] != *it1)
            return false;
        // else if (arr[*it2] != *it1)
        //     return false;
    }
    // map<char, char>::iterator itr1;
    // map<char, char>::iterator itr2;
    // for (itr1 = s12.begin(), itr2 = s21.begin(); *itr1 || *itr2; itr1++, itr2++)
    // {
    // }
    return true;
} */
bool is_isomorphic(string input1, string input2)
{
    char *arr = new char[256]();
    char *arr1 = new char[256]();
    string::iterator it1, it2;
    for (it1 = input1.begin(), it2 = input2.begin(); *it1 || *it2; it1++, it2++)
    {
        if (!arr[*it1])
            arr[*it1] = *it2;
        if (!arr1[*it2])
            arr1[*it2] = *it1;
        if ((arr[*it1] != *it2) || (arr1[*it2] != *it1))
            return false;
    }
    return true;
}
int main()
{
    cout << is_isomorphic("aaaa", "bbbb");
    return 0;
}