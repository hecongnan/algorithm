#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

void RadixSort(vector<int> &nums)
{
    int min = INT_MAX;
    for (int num : nums)
    {
        min = std::min(min, num);
    }

    int offset = -min;
    for (int &num : nums)
    {
        num += offset;
    }

    int max = INT_MIN;
    for (int num : nums)
    {
        max = std::max(max, num);
    }

    int length = 0;
    while (max > 0)
    {
        max /= 10;
        length++;
    }

    for (int i = 0; i < length; i++)
    {
        CountSort(nums, i);
    }

    for (int &num : nums)
    {
        num -= offset;
    }
}

void CountSort(vector<int> &nums, int k)
{

    vector<int> count(10, 0);

    for (int num : nums)
    {
        int digit = (num / static_cast<int>(pow(10, k))) % 10;
        count[digit]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> sorted(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int digit = nums[i] / static_cast<int>(pow(10, k)) % 10;
        sorted[count[digit] - 1] = nums[i];
        count[digit]--;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = sorted[i];
    }
}