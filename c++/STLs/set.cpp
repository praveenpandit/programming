// #include <iostream>
// #include <set>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s{1, 2, 2, 3};
    multiset<int> ms{1, 2, 3, 1, 0};
    cout << s.count(1) << endl;
    cout << s.size() << endl;
    cout << ms.count(1) << endl;
    cout << ms.size() << endl;
    for (auto i : ms)
        cout << i << "->";
    return 0;
}