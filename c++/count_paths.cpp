#include <iostream>
#include <vector>
using namespace std;

void count_path_rec(int rows, int cols, int r, int c, int *path)
{
    if (r == rows && c == cols)
    {
        *path += 1;
        return;
    }
    if (r <= rows)
        count_path_rec(rows, cols, r + 1, c, path);
    if (c <= cols)
        count_path_rec(rows, cols, r, c + 1, path);
}
int count_paths(int rows, int cols)
{
    int **m = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        m[i] = new int[cols];
        std::fill_n(m[i], cols, 1);
    }
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            m[i][j] = m[i - 1][j] + m[i][j - 1];
        }
    }
    return m[rows - 1][cols - 1];
    // if (rows == 1 || cols == 1)
    //     return 1;
    // else
    //     return count_paths(rows - 1, cols) + count_paths(rows, cols - 1);
    // int path = 0;
    // count_path_rec(rows, cols, 1, 1, &path);
    // return path;
}
int main()
{
    // std::vector<std::vector<int>, int> v(10, vector<int>(10, 1), 7);
    cout << v.at(2).at(2);
    // cout << count_paths(3, 3);
    return 0;
}