#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &A)
{
    vector<int> temp;
    bool flag = false;
    int k = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] || flag)
        {
            temp.push_back(A[i]);
            flag = true;
        }
    }
    for (int i = temp.size(); i > 0; i--)
    {
        if (++temp[i - 1] > 9)
            temp[i - 1] = 0;
        else
            break;
    }
    if (temp.size() == 0)
        temp.push_back(1);
    if (!temp[0])
        temp.insert(temp.begin(), 1);
    return temp;
}
int main()
{
    vector<int> arr = {0};
    for (auto i : plusOne(arr))
        cout << i << " ";
    cout << endl;
    return 0;
}