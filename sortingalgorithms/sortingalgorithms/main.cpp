//
//  main.cpp
//  sortingAlgorithms
//
//  Created by Karl-Henrik Horve on 06/10/2023.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include "./insertionSort.hpp"
#include "./shellSort.hpp"

void insertionSort(std::vector<int>& arr);
void shellSort(std::vector<char>& arr);
void display(const std::vector<int>& vec);
void populateIntArray(std::vector<int>& arr);
void populateCharArray(std::vector<char>& arr);

const int N = 20;


int main(int argc, const char * argv[]) {
    //Creating a random "array" of integers and then displaying it
    std::vector<int> arr(N+1);
    populateIntArray(arr);
    display(arr);
    std::cout << std::endl;
    
    insertionSort(arr);
    
    return 0;
}

// Prints length of array and the contents
void display (const std::vector<int>& vec) {
    std::cout << "Length of array: " << vec.size() << ". Contents: " << std::endl;
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i];
        if (i < vec.size()-1){
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Populates an array
void populateIntArray(std::vector<int>& arr) {
    std::srand(0);
    arr[0] = -1;
    for (int i = 1; i<= arr.size(); i++) {
        arr[i] = (std::rand() % 100) + 1;
    }
}

void populateCharArray(std::vector<char>& arr) {
    srand(0);
    arr[0] = ' ';                // sentinel key
    for (int i = 1;  i <= N;  i++) {
        arr[i] =  static_cast <char> ('A' + (rand() % 26));
    }
}

