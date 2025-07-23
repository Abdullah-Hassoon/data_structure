#pragma once

#include <cstddef>
#include <iostream>

class node{
    public:
        int data;
        node* next;    
};

class linkedList {
    public:
        linkedList();

        bool isEmpty() const;
        ~linkedList();

        void insertFirst(int value);
        void display() const;
        bool isFound(int value) const;
        void insertBefore(int value, int beforeValue);
        node* append(int value);
        node* removeItem(int value);
        int count() const;

        

    private:
        node* head;
};