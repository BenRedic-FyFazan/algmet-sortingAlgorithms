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

// Array sizes
const int N = 20;

int main(int argc, const char * argv[]) {
    char choice;
    
    while (true) {
        std::cout << "Please choose an option from the list below:" << std::endl;
        std::cout << "1: InsertionSort" << std::endl;
        std::cout << "2: Shellsort" << std::endl;
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
                shellsort(N);
            
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
