#include "linkedList.hpp"


linkedList::linkedList(): head(NULL){}


bool linkedList::isEmpty() const {
    return (head == NULL);
}

void linkedList::insertFirst(int value)  // Insert a new node at the beginning 
{
    if(head == NULL)  // is empty
    {
        head = new node();
        head->next = NULL;
        head->data = value;
    }
    else
    {
        node* newNode = new node();
        newNode-> data = value;
        newNode->next = head;
        head = newNode;
    }
}

void linkedList::display() const {
    std::cout << "linked list elements: ";
    node* temp = head;
    std::cout << temp->data << " "; 
    while((temp = temp->next) != NULL) {
        std::cout << temp->data << " ";
    }
    std::cout << std::endl;
}

bool linkedList::isFound(int value) const 
{
    node* temp = head;
    while(temp != NULL) {
        if(temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// inst the value before the first occurrence of beforeValue
void linkedList::insertBefore(int value, int beforeValue) {
    if(!isFound(beforeValue)) {
        std::cout << "Value " << beforeValue << " not found in the list." << std::endl;
        return;
    }

    if(head->data == beforeValue) {
        insertFirst(value);
        return;
    }
    node* currentNode = head;
    while(currentNode->next != NULL)
    {
        if(currentNode->next->data == beforeValue) {
            node* newNode = new node();
            newNode->data = value;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            return;
        }
        currentNode = currentNode->next;
    }
}

node* linkedList::append(int value) {
    node* newNode = new node();
    newNode->data = value;
    newNode->next = NULL;

    if(isEmpty()) {
        head = newNode;
        return head;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    return temp->next;
}

node* linkedList::removeItem(int value){
    if(isEmpty()){
        std::cout << "List is empty. Cannot remove item." << std::endl;
        return NULL;
    }
    if(isFound(value) == false){
        std::cout << "Item not found in the list." << std::endl;
        return NULL;
    }

    node* delPtr = head;
    
    // remove the first node case
    if(head->data == value){
        head = head->next;
        delete delPtr;
        return NULL;
    }
    // removove the other nodes
    node* prev = NULL;  // points to the previous node before the one to delete
    while(delPtr->data != value) {
        prev = delPtr;
        delPtr = delPtr->next;
    }
    prev->next = delPtr->next;  // skip the node to be deleted
    delete delPtr;  // free the memory of the deleted node
    return prev;
}

int linkedList::count() const
{
    int size = 0;
    node* ptr = head;
    while(ptr != NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}

linkedList::~linkedList() {
    node* current = head;
    node* nextNode;
    while(current != NULL) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = NULL;  // Set head to NULL after deletion
}
