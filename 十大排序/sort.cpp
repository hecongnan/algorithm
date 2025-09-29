//选择排序
void sort(vector<int>& nums){
    int sortedIndex = 0;
    int n = nums.size();
    while(sortedIndex < n){
        int minIndex = sortedIndex;
        for(int i = sortedIndex + 1;i < n;i++){
            if(nums[i] < nums[minIndex]){
                minIndex = i;
            }
        }
        int tmp = nums[sortedIndex];
            nums[sortedIndex] = nums[minIndex];
            nums[minIndex] = tmp;
        }
        sortedIndex++;
    }
