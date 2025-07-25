#include <iostream>
#include <list>

template<typename E>
class MyLinkedStack {
    std::list<E> stack;
public:
    //向栈顶添加元素，时间复杂度 O(1)
    void push(const E &e){
        stack.push_back(e);
    }
    //从栈顶弹出元素，时间复杂度 O(1)
    E pop(){
        E value = stack.back();
        stack.pop_back();
        return value;
    }
    //查看栈顶元素，时间复杂度 O(1)
    E peek() const {
        return stack.back();
    }
    //返回栈中的元素个数，时间复杂度 O(1)
    int size() const{
        return stack.size();
    }
};

int main(){
    MyLinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    while(stack.size() > 0){
        std::cout << stack.pop() << std::endl;
    }
    return 0;
    }
