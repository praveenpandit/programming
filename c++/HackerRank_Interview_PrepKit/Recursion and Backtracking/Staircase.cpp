// #include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

// Complete the stepPerms function below.
void stepPermsUntil(int n, int *count)
{
    if (n < 0)
        return;
    if (n == 0)
        *count++;
    else
    {
        stepPermsUntil(n - 3, count);
        stepPermsUntil(n - 2, count);
        stepPermsUntil(n - 1, count);
    }
}
int stepPerms(int n)
{
    int count = 0;
    stepPermsUntil(n, &count);
    return count;
}

int main()
{
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
