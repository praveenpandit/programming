#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {20};
    make_heap(v.begin(), v.end());
    v.push_back(45);
    push_heap(v.begin(), v.end());
    // cout << v.at(v.size() - 1) << endl;
    cout << v.size() << endl;
    cout << v.front() << endl;
    v.erase(v.begin());
    push_heap(v.begin(), v.end());
    cout << v.size() << endl;
    cout << v.front() << endl;
    // v.pop_back();
}
