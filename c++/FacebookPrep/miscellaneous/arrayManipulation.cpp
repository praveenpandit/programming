#include <iostream>
#include <vector>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> arr(n, 0);
    long sum = 0;
    for (auto query : queries)
    {
        for (int i = query[0] - 1; i < query[1]; i++)
        {
            arr[i] += query[2];
            sum = max(sum, arr[i]);
        }
    }
    return sum;
}
int main()
{
}