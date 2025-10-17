// 计数排序
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void CountSort(vector<int> &nums)
{
    if (nums.empty())
        return;
    int max = INT_MIN;
    int min = INT_MAX;

    for (int num : nums)
    {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    int offset = -min;
    vector<int> count(max - min + 1, 0);
    for (int num : nums)
    {
        count[num + offset]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> sorted(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        sorted[count[nums[i] + offset] - 1] = nums[i];
        count[nums[i] + offset]--;
    }
    nums = sorted;
}