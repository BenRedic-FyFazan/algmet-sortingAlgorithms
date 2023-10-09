//
//  quicksort.cpp
//  sortingalgorithms
//
//  Created by Karl-Henrik Horve on 09/10/2023.
//

#include "./quicksort.hpp"

/**
 * Functions same as Frodes example, but should be more readable.
 */
int partition(std::vector<char>&arr, int low, int high) {
    if (low < high) {
        char pivot = arr[high];
        int i = (low - 1);
        int j = high;
        
        while (true) {
            while (arr[++i] < pivot) ;
            while (arr[--j] > pivot) ;
            if (i >= j) {
                break;
            }
            std::swap(arr[i], arr[j]); // Builtin function for swapping two elements
        }
        std::swap(arr[i], arr[high]);
        
        // Printing
        std::cout << "Array sorted from element " << low << " to " << high << " for pivot element '" << pivot << "':" << std::endl;
        printArray(arr);
        std::cout << std::endl;
        
        // Returning position of partition element
        return i;
    }
    return 0;
}


/**
 * Same as Frodes example, with other naming conventions.
 */
void quicksort(std::vector<char>&arr, const int low, const int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        quicksort(arr, low, pIndex-1);
        quicksort(arr, pIndex+1, high);
    }
}


template <typename T>
void printArray(const std::vector<T>& arr) {
    std::cout << "[";
    for (int i = 1; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size()-1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
