// 希尔排序
void shellSort(vector<int> &nums)
{
    int n = nums.size();
    int h = 1;
    while (h < n / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        int sortedIndex = h;
        for (int i = sortedIndex; i >= h; i -= h)
        {
            if (nums[i] < nums[i - h])
            {
                int tmp = nums[i];
                nums[i] = nums[i - h];
                nums[i - h] = tmp;
            }
            else
            {
                break;
            }
        }
        sortedIndex++;
    }
    h = (h - 1) / 3;
}