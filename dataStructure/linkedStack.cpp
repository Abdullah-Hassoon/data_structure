#include "linkedStack.hpp"


linkedListStack::linkedListStack(): top(NULL) {}

bool linkedListStack::isEmpty()
{
    return (top == NULL);
}

void linkedListStack::push(int value){
    node* newNode = new node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int linkedListStack::pop(){
    int value = top->data;
    node* delPtr = top;
    top = top->next;
    delete delPtr;
    return value;
}

void linkedListStack::dispaly() const{
    node* temp = top;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

bool linkedListStack::isFull() const 
{
    node* ptr = new node();              // return NULL if the heap is full
    if(ptr == NULL)
    {
        std::cout << "The Stack is full";
    }
}

linkedListStack::~linkedListStack() {
    while (top != NULL) {
        node* temp = top;
        top = top->next;
        delete temp;
    }
}