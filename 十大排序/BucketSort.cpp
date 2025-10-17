#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void insertSort(vector<int> &nums);

void BucketSort(vector<int> &nums, int BucketCount)
{
    if (nums.empty() || BucketCount <= 0)
    {
        return;
    }
    int min = INT_MAX;
    int max = INT_MIN;

    for (int num : nums)
    {
        min = std::min(min, num);
        max = std::max(max, num);
    }

    int offset = -min;

    int BucketSize = (max - min) / BucketCount + 1;

    vector<vector<int>> buckets(BucketCount);

    for (int num : nums)
    {
        int index = (num + offset) / BucketSize;
        buckets[index].push_back(num);
    }

    for (int i = 0; i < BucketCount; i++)
    {
        insertSort(buckets[i]);
    }

    int index = 0;
    for (int i = 0; i < BucketCount; i++)
    {
        for (int num : buckets[i])
        {
            nums[index++] = num;
        }
    }
}

void insertSort(vector<int> &nums)
{
    int n = nums.size();
    int sortedIndex = 0;

    while (sortedIndex < n)
    {
        for (int i = sortedIndex; i > 0; i--)
        {
            if (nums[i] < nums[i - 1])
            {
                swap(nums[i], nums[i - 1]);
            }
            else
            {
                break;
            }
        }
        sortedIndex++;
    }
}