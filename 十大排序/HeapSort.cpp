#include <iostream>
#include <vector>

using namespace std;

const int parent(int node)
{
    return (node - 1) / 2;
}

const int left(int node)
{
    return node * 2 + 1;
}

const int right(int node)
{
    return node * 2 + 2;
}

void swap(vector<int> &heap, int i, int j)
{
    int tmp = heap[i];
    heap[i] = heap[j];
    heap[j] = tmp;
}

// 小顶堆的上浮操作，时间复杂度是树高 O(logN)
void minHeapSwim(std::vector<int> &heap, int node)
{
    while (node > 0 && heap[parent(node)] > heap[node])
    {
        swap(heap, parent(node), node);
        node = parent(node);
    }
}

// 小顶堆的下沉操作，时间复杂度是树高 O(logN)
void minHeapSink(std::vector<int> &heap, int node, int size)
{
    while (left(node) < size || right(node) < size)
    {
        // 比较自己和左右子节点，看看谁最小
        int min = node;
        if (left(node) < size && heap[left(node)] < heap[min])
        {
            min = left(node);
        }
        if (right(node) < size && heap[right(node)] < heap[min])
        {
            min = right(node);
        }
        if (min == node)
        {
            break;
        }
        // 如果左右子节点中有比自己小的，就交换
        swap(heap, node, min);
        node = min;
    }
}

// 大顶堆的上浮操作
void maxHeapSwim(std::vector<int> &heap, int node)
{
    while (node > 0 && heap[parent(node)] < heap[node])
    {
        swap(heap, parent(node), node);
        node = parent(node);
    }
}

// 大顶堆的下沉操作
void maxHeapSink(std::vector<int> &heap, int node, int size)
{
    while (left(node) < size || right(node) < size)
    {
        // 小顶堆和大顶堆的唯一区别就在这里，比较逻辑相反
        // 比较自己和左右子节点，看看谁最大
        int max = node;
        if (left(node) < size && heap[left(node)] > heap[max])
        {
            max = left(node);
        }
        if (right(node) < size && heap[right(node)] > heap[max])
        {
            max = right(node);
        }
        if (max == node)
        {
            break;
        }
        swap(heap, node, max);
        node = max;
    }
}

// 将输入的数组元素从小到大排序
void HeapSort(vector<int> &nums)
{
    // 第一步，原地建堆，注意这里创建的是大顶堆
    // 从最后一个非叶子节点开始，依次下沉，合并二叉堆
    int n = nums.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapSink(nums, i, n);
    }

    // 合并完成，现在整个数组已经是一个大顶堆

    // 第二步，排序，和刚才的代码一样
    int heapSize = n;
    while (heapSize > 0)
    {
        // 从堆顶删除元素，放到堆的后面
        swap(nums, 0, heapSize - 1);
        heapSize--;
        // 恢复堆的性质
        maxHeapSink(nums, 0, heapSize);
        // 现在 nums[0..heapSize) 是一个大顶堆，nums[heapSize..) 是有序元素
    }
}