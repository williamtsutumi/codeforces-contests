#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findClosestSum(
    vector<int> tasks,
    int target)
{
    if (tasks.size() == 0 || tasks.size() == 1)
        return 0;

    auto esq = tasks.begin();
    auto dir = tasks.begin();
    int sum = *esq;
    int melhorSum = sum;
    while (dir != tasks.end())
    {
        if (abs(sum - target) < abs(melhorSum - target))
            melhorSum = sum;

        if (sum > target)
        {
            sum -= *esq;
            esq++;
        }
        else
        {
            dir++;
            sum += *dir;
        }
    }
    // cout << "melhorsum: " << melhorSum << endl;
    return melhorSum;
}

int solve(vector<int> tasks)
{
    cout << "********************************" << endl;
    if (tasks.size() == 0)
        return 0;
    else if (tasks.size() == 1)
        return tasks.at(0);

    sort(tasks.begin(), tasks.end());
    auto esq = tasks.begin();
    auto dir = tasks.end() - 1;
    int sumEsq = *esq;
    int sumDir = *dir;
    vector<int> parteEsq;
    vector<int> parteDir;
    while (esq + 1 != dir)
    {
        if (sumEsq < sumDir)
        {
            esq++;
            sumEsq += *esq;
            parteEsq.push_back(*esq);
        }
        else
        {
            dir--;
            sumDir += *dir;
            parteDir.push_back(*dir);
        }
    }

    int diff;
    if (sumEsq > sumDir)
    {
        diff = sumEsq - sumDir;
        // cout << "Diff: " << diff << endl;
        return diff - 2 * findClosestSum(parteEsq, diff / 2);
    }
    else if (sumEsq < sumDir)
    {
        diff = sumDir - sumEsq;
        // cout << "Diff: " << diff << endl;
        return diff - 2 * findClosestSum(parteDir, diff / 2);
    }
    return 0;
}

int main()
{
    int numTasks;
    while (cin >> numTasks)
    {
        vector<int> tasks;
        while (numTasks--)
        {
            int task;
            cin >> task;
            tasks.push_back(task);
        }
        cout << solve(tasks) << endl;
    }

    return 0;
}