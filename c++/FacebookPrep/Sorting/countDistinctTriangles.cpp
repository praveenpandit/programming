#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> sides(3);

bool isSame(vector<long long> v1, vector<long long> v2)
{
    for (int i = 0; i < v1.size(); i++)
        if (v1[i] != v2[i])
            return false;
    return true;
}
// struct Ssides
// {
//     long long a;
//     long long b;
//     long long c;
// };

// void sortSides(struct Ssides &s)
// {
//     if (s.a < s.b)
//         swap(s.a, s.b);
//     if (s.c < s.b)
//     {
//         swap(s.c, s.b);
//         if (s.a < s.c)
//             swap(s.a, s.c);
//     }
// }
int countDistinctTriangles(vector<vector<long long>> arr)
{
    vector<bool> visited(arr.size(), false);
    for (int i = 0; i < arr.size(); i++)
        // sortSides(arr[i]);
        sort(arr[i].begin(), arr[i].end());
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (!visited[i])
            count++;
        visited[i] = true;
        for (int j = i + 1; j < arr.size() && !visited[j]; j++)
        {
            visited[j] = isSame(arr[i], arr[j]);
        }
    }
    return count;
}
int main()
{
    cout << countDistinctTriangles({{2, 2, 3}, {3, 2, 2}, {2, 5, 6}}) << endl;
    cout << countDistinctTriangles({{5, 8, 9}, {5, 9, 8}, {9, 5, 8}, {9, 8, 5}, {8, 9, 5}, {8, 5, 9}}) << endl;
    cout << countDistinctTriangles({{8, 4, 6}, {100, 101, 102}, {84, 93, 173}}) << endl;
    cout << countDistinctTriangles({{7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3}}) << endl;
    cout << countDistinctTriangles({{3, 4, 5}, {8, 8, 9}, {7, 7, 7}}) << endl;
    return 0;
}
