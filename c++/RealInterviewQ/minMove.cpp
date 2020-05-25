#include <iostream>
using namespace std;

int minMove(string str)
{
    char ch = str[0];
    int move = 0;
    int count = 0;
    for (auto i : str)
    {
        if (i == ch)
            count++;
        else
        {
            ch = i;
            move += count / 3;
            count = 1;
        }
    }
    return move += count / 3;
}

int main()
{
    cout << minMove("baabab");
    return 0;
}