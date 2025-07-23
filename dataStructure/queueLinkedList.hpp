#pragma once

class node{
    public:
        int data;
        node* next;
};

class queue{
    
    public:
        void enqueue(int value);    // add element to the back of the 
        int dequeue();              // remove the front element
        bool isEmpty();             // if empty return true
        bool isFull();              // if heap is full return true
        int peek();                 //        
        
    private:
        node* front;   // remove element from here
        node* back;    // add element here

};