#include <iostream>
#include <string>
using namespace std;

string findEncryptedWord_rec(string s, string &r)
{
    if (!s.size())
        return r;
    int len = s.size();
    if (len % 2 != 0)
    {
        int mid = len / 2;
        r.push_back(s[mid]);
        findEncryptedWord_rec(s.substr(0, mid), r);
        findEncryptedWord_rec(s.substr(mid + 1), r);
    }
    else
    {
        int mid = len / 2;
        if (mid > 0)
        {
            r.push_back(s[mid - 1]);
            findEncryptedWord_rec(s.substr(0, mid - 1), r);
            findEncryptedWord_rec(s.substr(mid), r);
        }
    }
    return r;
}
string findEncryptedWord(string s)
{
    string r = "";
    return findEncryptedWord_rec(s, r);
}
int main()
{
    cout << findEncryptedWord("facebook") << endl;
    cout << findEncryptedWord("abcxcba") << endl;
    cout << findEncryptedWord("abcd") << endl;
    return 0;
}