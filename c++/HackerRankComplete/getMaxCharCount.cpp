#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

/*
 * Complete the 'getMaxCharCount' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> getMaxCharCount(string s, vector<vector<int>> queries)
{
    // queries is a n x 2 array where queries[i][0] and queries[i][1] represents x[i] and y[i] for the ith query.
    vector<int> v;
    for (int i = 0; i < queries.capacity(); i++)
    {
        int j = queries[i][0];
        int count = 1;
        char max = std::toupper(s[j]);
        while (++j <= queries[i][1])
        {
            if (max < std::toupper(s[j]))
            {
                max = std::toupper(s[j]);
                count = 1;
            }
            else if (max == std::toupper(s[j]))
                count++;
        }
        // cout << char(max) << endl;
        v.push_back(count);
    }
    return v;
}

int main()
{
    vector<int> ret;
    vector<vector<int>> queries = {{2, 6}, {1, 2}};
    ret = getMaxCharCount("aAabBcba", queries);
    for (int i = 0; i < ret.capacity(); i++)
        cout << ret[i] << endl;
    return 0;
}