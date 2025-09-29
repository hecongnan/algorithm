// 冒泡排序
void bubbleSort(vector<int> &nums)
{
    int n = nums.size();
    int sortedIndex = 0;
    while (sortedIndex < n)
    {
        for (int i = n - 1; i > sortedIndex; i--)
        {
            if (nums[i] < nums[i - 1])
            {
                int tmp = nums[i];
                nums[i] = nums[i - 1];
                nums[i - 1] = tmp;
            }
        }
        sortedIndex++;
    }
}
