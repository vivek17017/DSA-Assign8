#define STACK_OVERFLOW 1;
#define STACK_UNDERFLOW 2;
#include<iostream>
using namespace std;
class Queue{
    private:
        int capacity;
        int top;
        int* ptr;
    public:
        Queue(int);
        void push(int);
        bool isFull();
        bool isEmpty();
        int peek();
        int pop();
        ~Queue();
        int getCapacity();
        void reverse(Queue&);

};
Queue::Queue(int cap){
    if(cap<0)
        cap=10;
    ptr=new int[cap];
    capacity=cap;
    top=-1;
}
bool Queue::isFull(){
    return (top==capacity-1);

}
bool Queue::isEmpty(){
    return (top==-1);

}
void Queue::push(int element){
    if(isFull)
        throw QUEUE_OVERFLOW;
    ptr[top+1]=element;
    top++;
}
int Queue::peek(){
    if(isFull)
        throw QUEUE_OVERFLOW;
    return ptr[top];
}
int Queue::pop(){
    if(isEmpty)
        throw STACK_UNDERFLOW;
    int item;
    item=ptr[top];
    top--;
    return item;
}

Queue::~Queue(){
    delete[]ptr;
}
int Queue::getCapacity(){
    return capacity;
}
void Queue::reverse(Queue &s){
    Queue temp1(s.getCapacity());
    while(!s.isEmpty()){
        temp1.push(s.pop());
    }
    Queue temp2(temp1.getCapacity());
    while(!temp1.isEmpty()){
        temp2.push(temp1.pop());
    }
    while(!temp2.isEmpty()){
        s.push(temp2.pop());
    }
}