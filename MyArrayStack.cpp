#include <vector>

template<typename E>
class MyArrayStack {
private:
    std::vector<E> list;
public:
    //向栈顶加入元素，时间复杂度是O(1)
    void push(const E& e){
        list.push_back(e);
    }
    //从栈顶删除元素，时间复杂度是O(1)
    E pop(){
        E value = list.back();
        list.pop_back();
        return value;
    }
    //返回栈顶元素，时间复杂度是O(1)
    E peek() const {
        return list.back();
    }
    //判断栈是否为空，时间复杂度是O(1)
    bool isEmpty() const {
        return list.empty();
    }
    //返回栈的大小，时间复杂度是O(1)
    int size() const {
        return list.size();
    }
};