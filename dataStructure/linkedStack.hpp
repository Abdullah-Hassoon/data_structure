#pragma once

#include <iostream>

class node
{
    public:
        int data;
        node* next;

        node(): data(0){
            next = NULL;
        }
};

class linkedListStack{
    public:
        linkedListStack();                    
        bool isEmpty();                         // return true if is empty   
        void push(int value);                   // push an element in the top location
        int pop();                              // pop 
        void dispaly() const;                   // display the stack   
        bool linkedListStack::isFull() const;   // check if stack is full by checking the heap if full then stack is full
        ~linkedListStack();

    private:
        node* top;
};