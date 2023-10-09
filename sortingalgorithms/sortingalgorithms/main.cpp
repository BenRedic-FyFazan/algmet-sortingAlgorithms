//
//  main.cpp
//  sortingAlgorithms
//
//  Created by Karl-Henrik Horve on 06/10/2023.
//

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "./insertionSort.hpp"
#include "./shellSort.hpp"
#include "./quicksort.hpp"

std::vector<char> stringToCharVec(const std::string& str);
template <typename T>
void printArray(const std::vector<T>& arr);

// Array sizes
const int N = 20;

int main(int argc, const char * argv[]) {
    
    // Creating array for example
    //std::vector<char> arr(N+1);
    //populateCharArray(arr, N+1);
    
    std::vector<char> arr = stringToCharVec("KOMPLIKASJON");
    
    char choice;
    
    while (true) {
        std::cout << "Please choose an option from the list below:" << std::endl;
        std::cout << "1: InsertionSort" << std::endl;
        std::cout << "2: Shellsort" << std::endl;
        std::cout << "3: Quicksort" << std::endl;
        std::cout << "Enter 'q' or '0' to quit." << std::endl;
        
        std::cin >> choice;
        choice = tolower(choice);
        
        switch (choice) {
            case '1':
                std::cout << "Starting Insertionsort example." << std::endl;
                insertionSort(N);
                break;
                
            case '2':
                std::cout << "Starting Shellsort example." << std::endl;
                shellsort(arr);
                break;
                
            case '3':
                std::cout << "Starting Quicksort example." << std::endl << "Array before sorting: ";
                printArray(arr);
                quicksort(arr, 1, int(arr.size())-1);
                std::cout << "After sorting:" << std::endl;
                printArray(arr);
                std::cout << std::endl;
                break;
                
            case '0': // Waterfalls into case 'q'
            case 'q':
                std::cout << "Exiting program..." << std::endl;
                return 0;
            
            default:
                std::cout << "Invalid choice. Please enter a valid option or 'q' to quit." << std::endl;
        }
    }
    
    return 0;
}


std::vector<char> stringToCharVec(const std::string& str) {
    std::vector<char> charVec;
    charVec.push_back(' '); //sentinel key
    for (char c: str) {
        charVec.push_back(c);
    }
    return charVec;
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
