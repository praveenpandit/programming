#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isMapEqual(map<char, int> ms, map<char, int> mt)
{
    for (auto i : mt)
    {
        if (ms.count(i.first))
        {
            if (i.second > ms[i.first])
                return false;
        }
        else
            return false;
    }
    return true;
}
map<char, int> getMap(string s)
{
    map<char, int> mt;
    for (auto i : s)
    {
        if (mt.count(i))
            mt[i]++;
        else
        {
            pair<char, int> temp = {i, i};
            // mt.insert(pair(i, 1));
            mt.insert(temp);
        }
    }
    return mt;
}
int minLengthSubstring(string s, string t)
{
    map<char, int> mt = getMap(t);
    for (int len = t.length(); len <= s.length(); len++)
    {
        for (int i = 0; i < s.length() - len; i++)
        {
            map<char, int> ms = getMap(s.substr(i, len));
            if (isMapEqual(ms, mt))
                return len;
        }
    }
    return -1;
}
/* int minLengthSubstring(string s, string t)
{

    map<char, int> mt;
    for (auto i : t)
    {
        if (mt.count(i))
            mt[i]++;
        else
            mt.insert(pair(i, 1));
    }
    for (int i = t.length(); i < s.length(); i++)
    {
        for (int j = 0; j < s.length() - i; j++)
        {
            int k = i;
            int t = j;
            map<char, int> ms;
            do
            {
                if (ms.count(s[t]))
                    ms[s[t]]++;
                else
                    ms.insert(pair(s[t], 1));
                t++;
            } while (--k);
            if (isMapEqual(ms, mt))
                return i;
        }
    }
    return -1;
} */
void subString(string s)
{
    for (int len = 2; len <= s.length(); len++)
        for (int i = 0; i < s.length() - len; i++)
            cout << s.substr(i, len) << endl;
}
int main()
{
    // subString("dcbefebce");
    // cout << string("dcbefebce").length() - string("fd").length() << endl;
    cout << minLengthSubstring("dcbefebce", "fd") << endl;
    cout << minLengthSubstring("bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf", "cbccfafebccdccebdd") << endl;
    return 0;
}