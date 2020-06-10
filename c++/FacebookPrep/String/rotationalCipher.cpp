#include <iostream>
#include <string>
using namespace std;

char &rotationalCipher_until(char &ch, int f)
{
    if (f == 0)
        return ch;
    if (ch >= 'a' && ch <= 'z')
        ch = ch + 1 > 'z' ? 'a' : ch + 1;
    else if (ch >= 'A' && ch <= 'Z')
        ch = ch + 1 > 'Z' ? 'A' : ch + 1;
    else if (ch >= '0' && ch <= '9')
        ch = ch + 1 > '9' ? '0' : ch + 1;
    return rotationalCipher_until(ch, f - 1);
}

string rotationalCipher(string input, int rotationFactor)
{
    for (int i = 0; i < input.length(); i++)
        input[i] = rotationalCipher_until(input[i], rotationFactor);
    return input;
}

int main()
{
    cout << rotationalCipher("Zebra-493?", 3) << endl;
    cout << rotationalCipher("abcdefghijklmNOPQRSTUVWXYZ0123456789", 39) << endl;
    return 0;
}