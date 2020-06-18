#include <iostream>
#include <vector>
using namespace std;

int findMedian(vector<vector<int>> A, int &count, int row = 1, int col = 1)
{

    if (count == 4)
        return count;
    if (count < 4)
        findMedian(A, count, row + 1, col);
    else
        findMedian(A, count, row, col + 1);
    count = 0;
    for (int i = 0; i <= row; i++)
        for (int j = 0; j <= col; j++)
            count++;
    return count;
}

int main()
{
    int count = 0;
    cout << findMedian({{1, 3, 5}, {2, 6, 9}, {3, 6, 9}}, count);
    return 0;
}