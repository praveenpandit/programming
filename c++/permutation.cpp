#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

// bool permutation(string input1, string input2)
// {
// }
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void permute(char *str, int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(&str[i], &str[l]);
            permute(str, l + 1, r);
            swap(&str[i], &str[l]);
        }
    }
}
void permutation(string input1, int l, int r, string input2, bool *b)
{
    if (*b)
        return;
    if (l == r && !input1.compare(input2))
    {
        // if (!input1.compare(input2))
        *b = *b || true;
    }
    else
    {
        for (int i = l; i < r; i++)
        {
            std::swap(input1[i], input1[l]);
            permutation(input1, l + 1, r, input2, b);
            std::swap(input1[i], input1[l]);
        }
        // return false;
    }
}

int main()
{
    char str[] = "ABC";
    string s = "ABC";

    bool b = false;
    permutation(s, 0, s.length(), "ABB", &b);
    cout << b;
    // cout << s.length();
    // permute(str, 0, 2);
    return 0;
}