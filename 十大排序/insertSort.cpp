// 插入排序
void insertSort(vector<int> &nums)
{
    int n = nums.size();
    int sortedIndex = 0;
    for (int i = sortedIndex; i > 0; i--)
    {
        if (nums[i] < nums[i - 1])
        {
            int tmp = nums[i];
            nums[i] = nums[i - 1];
            nums[i - 1] = tmp;
        }
        else
        {
            break;
        }
    }
    sortedIndex++;
}