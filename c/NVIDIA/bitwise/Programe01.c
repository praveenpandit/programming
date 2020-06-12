#include <stdio.h>
#include <inttypes.h>

void isEven(unsigned int i)
{
    // i *= -1;
    !(i & 1) ? printf("EVEN\n") : printf("ODD\n");
}

int isDivisibleBy17(int n)
{
    if (n == 0 || n == 17)
        return 1;
    if (n < 17)
        return 0;
    // n/17 = n/16 - n/17*16 -> n>>4 - n%15
    return isDivisibleBy17((n >> 4) - (n & 15));
}
int isDivisibleBy9(int n)
{
    if (n == 0 || n == 9)
        return 1;
    if (n < 9)
        return 0;
    // n/9 = n/8 - n/9*8 -> n>>3 - n%7
    return isDivisibleBy9((n >> 3) - (n & 7));
}
void getLeastSetBit(int x)
{
    printf("0x%x\n", (x & -x));
}
int main()
{
    int i = 17;
    isEven(i);
    getLeastSetBit(i);
    if (isDivisibleBy17(i))
        printf("yes\n");
    else
        printf("No\n");
    if (isDivisibleBy9(i))
        printf("yes\n");
    else
        printf("No\n");

    // if (0x12345678 >> 4 & 0x0000000f)
    //     printf("Little-endian\n");
    // else
    //     printf("Big-endian\n");

    // printf("Endian :: 0x%x\n", 0x12345678);

    uint32_t le = 0x12345678;
    uint32_t be = __builtin_bswap32(le);

    printf("Little-endian: 0x%" PRIx32 "\n", le);
    printf("Big-endian:    0x%" PRIx32 "\n", be);

    char *ch = (char *)&le;
    printf("0x%x", *(ch));
    if (*ch == 0x78)
        printf("Little-endian\n");
    else
        printf("Big-endian\n");
    return 0;
}