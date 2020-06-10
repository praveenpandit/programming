#include <iostream>
#include <string>
using namespace std;

int countMatchingPairs(string s, string t)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == t[i])
            count++;
    return count;
}
int matchingPairs(string s, string t)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i + 1; j < s.length(); j++)
        {
            std::swap(s[i], s[j]);
            count = std::max(count, countMatchingPairs(s, t));
            std::swap(s[i], s[j]);
        }
    }
    return count;
}
int main()
{
    cout << matchingPairs("abcd", "abcd") << endl;
    return 0;
}