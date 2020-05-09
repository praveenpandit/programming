#include <iostream>

using namespace std;

int fibonacci(int n)
{
    // Complete the function.
    if (n == 0 || n == 1)
        return n;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
    // return n;
}

int main()
{
    int n = 5;
    // cin >> n;
    cout << fibonacci(n);
    return 0;
}