#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class BITArray
{
    vector<int> array;

public:
    BITArray(vector<int> list)
    {
        array = vector<int>(list.size() + 1, 0);
        for (int i = 0; i < list.size(); i++)
            array[i + 1] = list[i];
        for (int i = 1; i < list.size(); i++)
        {
            int idx = i + (i & -i);
            if (idx < array.size())
                array[idx] += array[i];
        }
    }
    int prefixSum(int id)
    {
        int result = 0;
        for (++id; id > 0; id -= id & -id)
            result += array[id];
        return result;
    }
    int rangeSum(int to, int from = 0)
    {
        if (!from)
            return prefixSum(to);
        return prefixSum(to) - prefixSum(from - 1);
    }
    void add(int id, int data)
    {
        for (++id; id > 0; id += id & -id)
            array[id] += data;
    }
    void printBITArray()
    {
        for (int i = 1; i < array.size(); i++)
            cout << setw(3) << array[i];
    }
};
int main()
{
    vector<int> array{1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5};
    BITArray bit(array);
    bit.printBITArray();
    return 0;
}