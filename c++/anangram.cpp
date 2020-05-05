#include <iostream>
#include <string>
using namespace std;

bool is_anangram(string input1, string input2)
{
    int *arr = new int[256]();
    string::iterator it1, it2;
    for (it1 = input1.begin(), it2 = input2.begin(); *it1 || *it2; it1++, it2++)
    {
        arr[*it1]++;
        arr[*it2]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    cout << is_anangram("firecode", "firec") << endl;
    return 0;
}