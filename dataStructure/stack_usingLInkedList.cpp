#include "linkedList.hpp"
#include <iostream>


class Stack{
    private:
        linkedList list;
        node* top;  // pointer to the top of the stack
    public:
        Stack(): top(NULL) {}
        void push(int value)  // add element at the top of the stack
        {
            top = list.append(value); // return a pointer to the last node
        }
        void pop()         // remove the last element
        {
            top = list.removeItem(top->data);
        }
        void peek()       // print the last element
        {
            std::cout << "The top element: " << top->data << "\n";
        }
        void displayStack()
        {
            list.display();
        }
        bool isEmpty(){
            return (top == NULL);
        }
        int countStack(){
            return list.count();
        }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.displayStack();
    st.peek();
    st.pop();
    st.peek();
    st.pop();
    st.displayStack();
    st.push(100);
    st.push(200);
    st.peek();
    st.pop();
    st.peek();
}