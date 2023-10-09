//
//  quicksort.hpp
//  sortingalgorithms
//
//  Created by Karl-Henrik Horve on 09/10/2023.
//

#ifndef quicksort_hpp
#define quicksort_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
int partition(std::vector<char>&arr, int low, int high);
void quicksort(std::vector<char>&arr, const int low, const int high);
template <typename T>
void printArray(const std::vector<T>& arr);

#endif /* quicksort_hpp */
