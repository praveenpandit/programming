#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v{1, 2, 4};
    // cout << v.back() << "->";
    // v.clear();
    cout << v.capacity() << endl;
    cout << v.size() << endl;
    v.push_back(2);
    for (auto i : v)
        cout << i << "->";
    int a = 10, b = 20;
    cout << endl;
    cout << a << "=" << b << endl;
    std::swap(a, b);
    cout << a << "=" << b << endl;
    return 0;
}