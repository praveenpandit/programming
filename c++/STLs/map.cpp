#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<const int, char> m{{1, 'a'}};
    cout << m.size() << endl;
    cout << m.at(1) << endl;
    // map<int, char>::iterator it;
    // for (it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->first << "<->" << it->second;
    // }
    for (auto i : m)
        cout << i.first << i.second << endl;
    return 0;
}