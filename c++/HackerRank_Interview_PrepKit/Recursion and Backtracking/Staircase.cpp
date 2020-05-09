// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

// Complete the stepPerms function below.
void stepPermsUntil(int n, int count[])
{
    if (n < 0)
        return;
    else if (n == 1 || n == 0)
    {
        count[n] = 1;
    }
    else if (n == 2)
    {
        count[n] = 2;
    }
    else if (count[n] == 0)
    {
        stepPermsUntil(n - 3, count);
        stepPermsUntil(n - 2, count);
        stepPermsUntil(n - 1, count);
        count[n] = count[n - 3] + count[n - 2] + count[n - 1];
    }
}
int stepPerms(int n)
{
    int *count = new int[n + 1]();
    stepPermsUntil(n, count);
    return count[n];
}

int main()
{
    // cout << stepPerms(4);
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++)
    {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
