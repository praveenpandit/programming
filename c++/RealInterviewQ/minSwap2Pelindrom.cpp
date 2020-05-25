#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, vector<int>> buildVector(string str)
{
    map<char, vector<int>> mp;
    int i = 0;
    for (auto ch : str)
        mp[ch].push_back(i++);
    return mp;
}
void displayMap(map<char, vector<int>> m)
{
    for (auto i : m)
    {
        cout << i.first << " = ";
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    }
}
bool isPelindromPossible(map<char, vector<int>> mp)
{
    int odd = 0;
    for (auto i : mp)
        if (i.second.size() % 2 && odd <= 1)
            odd++;
    return (odd > 1) ? false : true;
}
bool isInBoundary(vector<int> v1, vector<int> v2)
{
    return (v1[0] > v2[0] &&
            v1[0] < v2[v2.size() - 1] &&
            v1[v1.size() - 1] > v2[0] &&
            v1[v1.size() - 1] < v2[v2.size() - 1])
               ? true
               : false;
}
int main()
{
    map<char, vector<int>> m;
    m = buildVector("madam");
    displayMap(m);
    // cout << isPelindromPossible(m);
    cout << isInBoundary(m['a'], m['d']);
    return 0;
}