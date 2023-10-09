//
//  insertionSort.cpp
//  sortingAlgorithms
//
//  Created by Karl-Henrik Horve on 06/10/2023.
//

#include "./insertionSort.hpp"
#include <iostream>

void insertionSort(const int arrSize) {
    
    //Creating a random "array" of integers and then displaying it
    std::vector<int> arr(arrSize+1);
    populateIntArray(arr);
    display(arr);
    std::cout << std::endl;
    
    
    int step = 1; // Algorithm iterations
    for (int i = 1;  i < arr.size();  i++) {
        int j = i;
        int valueToSort = arr[i];
        
        // Gradually shifts elements to the right until 'j-1' is less than or equal to 'value'
        while ( j > 0 && arr[j-1] > valueToSort) {
            arr[j] = arr[j-1];
            arr[j-1] = valueToSort;
            j--;
        }
        
        displaySortingStep(arr, step, valueToSort, i, j);
        step++;
    }
    
    std::cout << "Sorting complete!" << std::endl;
}


void displaySortingStep(const std::vector<int>& arr, int step, int valueToSort, int i, int j) {
    std::cout << "Step " << step++ << ": Move value '" << valueToSort << "' from array[" << i << "] to array[" << j << "]." << std::endl;
    std::cout << "[";
    for (int k = 0; k < arr.size(); k++) {
        std::cout << arr[k];
        if (k < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Press enter to continue iteration..." << std::endl;
    std::cin.get();
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
