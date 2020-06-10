#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool sortmap(const pair<int, char> &a, const pair<int, char> &b)
{
    return (a.first < b.first);
}
int main()
{
    map<const int, char> m{{1, 'a'}};
    m.insert(pair(7, 'd'));
    m.insert(pair(3, 'f'));
    m.insert(pair(2, 'v'));
    // m.insert(pair(2, 'd'));
    // auto max = get_max(m);
    // cout << m.size() << endl;
    // cout << m.at(0) << endl;
    // cout << m.at(4) << endl;
    cout << m.count(4) << endl;
    // cout << m.at(2) << endl;
    // cout << m.at(3) << endl;
    // cout << m.at(7) << endl;
    // sort(m.begin(), m.end(), sortmap);
    // cout << max.first << endl;
    // cout << m.rbegin() << endl;
    // map<int, char>::iterator it;
    // for (it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << "<->" << it->second;
    // }
    for (auto i : m)
        cout << i.first << "-" << i.second << endl;

    return 0;
}