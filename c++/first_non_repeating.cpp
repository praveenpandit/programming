#include <iostream>
#include <string>
#include <queue>
using namespace std;
char first_non_repeating(string str)
{
    string::iterator it;
    queue<char> q;
    int *arr = new int[256]();
    for (it = str.begin(); it != str.end(); it++)
    {
        q.push(*it);
        arr[*it]++;
    }
    while (!q.empty())
    {
        if (arr[q.front()] == 1)
            return q.front();
        q.pop();
    }
    return '0';
}
int main()
{
    cout << first_non_repeating("cbcd");
    return 0;
}