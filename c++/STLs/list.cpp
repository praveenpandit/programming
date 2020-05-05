#include <iostream>
#include <list>

using namespace std;

int main()
{
    std::list<int> l{7, 16, 5, 16, 16, 8};
    l.erase(l.begin());
    l.pop_front();
    // l.remove(16);
    for (auto i : l)
        cout << i << "->";
    // list<int>::iterator i;
    // l.sort();
    // for (i = l.begin(); i != l.end(); i++)
    // {
    //     cout << *i << "->";
    // }
    // cout << l.size();
    return 0;
}