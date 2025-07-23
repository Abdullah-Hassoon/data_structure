#include <iostream>

/*
    size of the array is dynamic of type int
    Data item:
        size;
        pointer to the array;
        lenght: get the number of elements in the array;

    Operations:
        - create the array; in constructor
        - 


*/

class Array {

    private:
        int size;
        int length;
        int* arr;
    public:
        Array(int arrSize) : size(arrSize), length(0) {
            arr = new int[arrSize];
        }

        void fillArray(){
            int no_of_elements;
            std::cout << "Enter the number of elements to fill in the array (max "<< size << "): ";
            std::cin >> no_of_elements;
            if (no_of_elements > size) {
                std::cout << "Error: Number of elements exceeds array size." << std::endl;
                return;
            }
            else
            {
                for(int i = 0; i < no_of_elements; i++) {
                    std::cout << "Enter element " << (i + 1) << ": ";
                    std::cin >> arr[i];
                }
                length += no_of_elements;
            }
        }

        void displayArray() const {
            std::cout << "Array elements: ";
            for (int i = 0; i < length; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }

        int getLength() const {
            return length;
        }

        int getSize() const {
            return size;
        }

        int serach(int value) const {
            for (int i = 0; i < length; i++) {
                if (arr[i] == value) {
                    return i; // Return the index of the found element
                }
            }
            return -1; // Return -1 if the element is not found
        }

        void append(int newValue){
            if(size == length) {
                std::cout << "Error: Array is full. Cannot append new value." << std::endl;
                return;
            }
            else {
                arr[length] = newValue;
                length++;
            }
        }

        void insert(int index, int newValue){
            for(int i = length - 1; i > index; i--){
                if (i < size - 1)
                    arr[i + 1] = arr[i]; // Shift elements to the right by one position
            }
            arr[index] = newValue; // Insert the new value at the specified index
            length++;
        }
};
