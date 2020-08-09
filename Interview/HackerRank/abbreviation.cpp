#include <iostream>
#include <string>
using namespace std;

bool abbreviationUntil(string a, string b)
{
    if (a.length() == 0 && b.length() != 0)
        return false;
    if (a.length() != 0 && b.length() == 0)
    {
        for (auto i : a)
        {
            if (i < 'a' || i > 'z')
                return false;
        }
        return true;
    }
    if (b.length() == 0)
        return true;
    if (a[0] == b[0] || ('A' + a[0] - 'a' == b[0]))
        return true && abbreviationUntil(a.erase(0, 1), b.erase(0, 1));
    else
        return true && abbreviationUntil(a.erase(0, 1), b);
}
string abbreviation(string a, string b)
{
    return abbreviationUntil(a, b) ? "YES" : "NO";
}
int main()
{
    cout << abbreviation("LLZOSYAMQRMBTZXTQMQcKGLR", "LLZOSYAMBTZXMQKLR") << endl;
    return 0;
}