#include <iostream>
#include <vector>
using namespace std;
void minimumBribes(vector<int> q)
{
    int sum = 0;
    q.insert(q.begin(), 0);
    for (int i = q.size() - 1; i > 0; i--)
    {
        if (q[i] - i > 2)
        {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(1, (q[i] - 2)); j < i; j++)
            if (q[j] > q[i])
                sum++;
    }
    cout << sum << endl;
}
int main()
{
    minimumBribes({2, 1, 5, 3, 4});
    minimumBribes({1, 2, 5, 3, 7, 8, 6, 4});
    return 0;
}