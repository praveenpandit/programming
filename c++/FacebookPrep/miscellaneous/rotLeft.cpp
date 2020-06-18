#include <iostream>
#include <vector>
using namespace std;

vector<int> rotLeft(vector<int> a, int d)
{

    int id = 0;
    d = (a.size() - d) < 0 ? (a.size() - d) * -1 : (a.size() - d);
    // if (d >= a.size())
    //     return a;
    for (int i = 0; i < a.size(); i++)
    {
        if (i + d < a.size())
            swap(a[i], a[i + d]), id = i;
        else
            swap(a[i], a[a.size() - 1]);
    }
    cout << id << endl;
    // for (int i = id + 1; id && i < a.size() - 1; i++)
    //     if (id % 2)
    //         swap(a[i], a[a.size() - 1]);
    //     else
    //         swap(a[i], a[i + 1]);
    return a;
}
int main()
{
    for (auto i : rotLeft({1, 2, 3, 4, 5, 6}, ))
        cout << i << " ";
    return 0;
}