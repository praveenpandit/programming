#include <iostream>
#include <vector>

using namespace std;

int sumRevenue(vector<int> arr, int milestone, int *id)
{
    for (int i = *id; i < arr.size(); i++)
    {
        int sum = 0;
        int temp = i;
        while (temp)
        {
            sum += arr[temp];
            temp -= temp & -temp;
        }
        if (sum >= milestone)
            return *id = i;
    }
    return -1;
}

vector<int> getMilestoneDays(vector<int> revenues, vector<int> milestones)
{
    vector<int> m_revenues = vector<int>(revenues.size() + 1, 0);
    vector<int> m_milestones = vector<int>(milestones.size(), 0);

    for (int i = 0; i < revenues.size(); i++)
        m_revenues[i + 1] = revenues[i];
    for (int i = 1; i < m_revenues.size(); i++)
    {
        int id = i + (i & -i);
        if (id < m_revenues.size())
            m_revenues[id] += m_revenues[i];
    }
    int k = 0;
    int j = 1;
    for (auto i : milestones)
        m_milestones[k++] = sumRevenue(m_revenues, i, &j);
    for (auto i : m_revenues)
        cout << i << " ";
    cout << endl;

    return m_milestones;
}

int main()
{
    // for (auto i : getMilestoneDays({10, 20, 30, 40, 50, 60, 70, 80, 90, 100}, {100, 200, 500}))
    for (auto i : getMilestoneDays({700, 800, 600, 400, 600, 700}, {3100, 2200, 800, 2100, 1000}))
        cout << i << " ";
    cout << endl;
    return 0;
}