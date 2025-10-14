#include <iostream>
#include <vector>

using namespace std;

template <typename T>

class MyPriorityQueue
{
    vector<T> heap;

    int size;

    // 元素比较器
    function<bool(const T &, const T &)> comparator;

    // 调整堆的大小
    void resize(int capacity)
    {
        if (capacity > size)
        {
            heap.resize(capacity);
        }
    }

    void swap(vector<int> &heap, int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    int parent(int node)
    {
        return (node - 1) / 2;
    }

    int left(int node)
    {
        return 2 * node +1;
    }
    
    int right(int node)
    {
        return 2 * node + 2;
    }

    void maxHeapSwim(vector<int> &heap, int node)
    {
        while (node > 0 && heap[parent(node)] < heap[node])
        {
            swap(heap, node, parent(node));
            node = parent(node);
        }
    }

    void maxHeapSink(vector<int> &heap, int node, int size)
    {
        while (left(node) < size || right(node) < size)
        {
            int max = node;
            if (left(node) < size && heap[left(node)] > heap[node])
            {
                max = left(node);
            }
            if (right(node) < size && heap[right(node)] > heap[node])
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

    void minHeapSwim(vector<int> &heap, int node)
    {
        while (node > 0 && heap[parent(node)] > heap[node])
        {
            swap(heap, node, parent(node));
            node = parent(node);
        }
    }

    void minHeapSink(vector<int> &heap, int node, int size)
    {
        while (left(node) < size || right(node) < size)
        {
            int min = node;
            if (node < size && heap[left(node)] < heap[node])
            {
                min = left(node);
            }
            if (node < 0 && heap[right(node)] < heap[node])
            {
                min = right(node);
            }
            if (min == node)
            {
                break;
            }
            swap(heap, node, min);
            node = min;
        }
    }

public:
    MyPriorityQueue(int capacity, function(bool(const T &, const &) conparator)) : heap(capacity), size(0), comparator(move(comparator)) {}

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    // 查，返回堆顶元素，时间复杂度 O(1)
    const T &peek() const
    {
        if (isEmpty())
        {
            throw std::underflow_error("Priority queue underflow");
        }
        return heap[0];
    }

    // 增，向堆中插入元素，时间复杂度 O(log n)
    void push(const T &x)
    {
        // 扩容
        if (size == heap.size())
        {
            resize(2 * heap.size());
        }
        // 把新元素追加到最后
        heap[size] = x;
        // 然后上浮到正确位置
        swim(size);
        size++;
    }

    // 删，删除堆顶元素，时间复杂度 O(log n)
    T pop()
    {
        if (isEmpty())
        {
            throw std::underflow_error("Priority queue underflow");
        }
        T res = heap[0];
        swap(heap, 0, size - 1);
        size--;
        sink(0);
        // 缩容
        if (size > 0 && size == heap.size() / 4)
        {
            resize(heap.size() / 2);
        }
        return res;
    }
};