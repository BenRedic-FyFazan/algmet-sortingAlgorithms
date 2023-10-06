//
//  insertionSort.cpp
//  sortingAlgorithms
//
//  Created by Karl-Henrik Horve on 06/10/2023.
//

#include "./insertionSort.hpp"
#include <iostream>

void displaySortingStep(const std::vector<int>& arr, int step, int value, int i, int j);

void insertionSort(std::vector<int>& arr) {
    std::cout << "Starting insertion sort algorithm..." << std::endl;
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
