#include <iostream>
#include <vector>

template<typename E>
class MyArrayQueue {
private:
    CycArray<E> arr;
public:
    MyArrayQueue(){
        arr = CycleArray<E>();
    }
    
    void push(E t){
        arr.addLast(t);
    }
    
    E pop(){
        return arr.removeFirst();
    }

    E peek(){
        return arr.getFirst();
    }

    int size() {
        return arr.size();
    }
};