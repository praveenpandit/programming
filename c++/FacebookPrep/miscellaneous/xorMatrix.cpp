#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> xorMatrix(int m, vector<int> first_row)
{
    for (int i = 1; i < m; i++)
    {
        vector<int> temp(first_row.size());
        for (int j = 0; j < first_row.size(); j++)
        {
            temp[j] = first_row[j] ^ first_row[(j + 1) % first_row.size()];
        }
        first_row = temp;
    }
    return first_row;
}
int main()
{
    for (auto i : xorMatrix(2, {6, 7, 1, 3}))
        cout << i << " ";
    cout << endl;
    return 0;
}