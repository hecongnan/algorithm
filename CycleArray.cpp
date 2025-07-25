#include <iostream>
#include <vector>
#include <stdexcept>
#include <ostream>

template<typename T>
class CycleArray{
    std::vector<T> arr;
    int start;
    int end;
    int count;

    //自动扩缩容辅助函数
    void resize(int newSize){
        std::vector<T> newArr(newSize);
        for(int i = 0; i < count; ++i){
            newArr[i] = arr[(start+i) % arr.size()];
        }
        arr = std::move(newArr);
        start = 0;
        end = count;
    }
public:
    CycleArray() : CycleArray(1){}
    explicit CycleArray(int size)
      :arr(size), start(0), end(0),count(0){}

      //在数组头部添加元素，时间复杂度 O(1)
      void addFirst(const T& val){
        if(isFull()){
            resize(arr.size() * 2);
        }
        //start是闭区间，所以先左移，再赋值
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = val;
        count++;
      }

      //删除数组头部元素，时间复杂度 O(1)
      void removeFirst(){
        if(isEmpty()){
            throw std::runtime_error("Array is empty");
        }
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        if(count > 0 && count == arr.size() / 4){
            resize(arr.size() / 2);
        }
      }
       //在数组尾部添加元素，时间复杂度 O(1)
       void addLast(const T& val){
        if(isFull()){
            resize(arr.size() * 2);
        }
        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
       }

       //删除数组尾部元素，时间复杂度 O(1)
       void removeLast(){
        if(isEmpty()){
            throw std::runtime_error("Array is empty");
        }
        end = (end - 1 + arr.size()) % arr.size();
        arr[end] = T();
        count--;
        if(count > 0 && count == arr.size() / 4){
            resize(arr.size() / 2);
        }
       }

       //获取数组头部元素，时间复杂度 O(1)
       T getFirst() const {
        if(isEmpty()){
            throw std::runtime_error("Array is empty");
        }
        return arr[start];
       }

       //获取数组尾部元素，时间复杂度 O(1)
       T getLast() const {
        if(isEmpty()){
            throw std::runtime_error("Array is empty");
        }
        return arr[(end - 1 + arr.size()) % arr.size()];
       }

       bool isFull() const{
        return count == arr.size();
       }

       int size() const{
        return count;
       }

       bool isEmpty() const {
        return count == 0;
       }
};