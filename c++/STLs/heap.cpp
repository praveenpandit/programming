#include <iostream>
#include <vector>

using namespace std;

int main()
{

    // Initializing a vector
    vector<int> v1 = {20, 30, 40, 25, 15};
    make_heap(v1.begin(), v1.end());
    cout << "The maximum element of heap is : " << v1.front() << endl;
    v1.push_back(50);
    push_heap(v1.begin(), v1.end());
    cout << "The maximum element of heap after push is : " << v1.front() << endl;

    pop_heap(v1.begin(), v1.end());
    // v1.pop_back();
    cout << "The maximum element of heap after pop is : " << v1.front() << endl;

    pop_heap(v1.begin(), v1.end() - 1);
    // v1.pop_back();
    cout << "The maximum element of heap after pop is : " << v1.front() << endl;

    return 0;
}
/* int main()
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
} */
