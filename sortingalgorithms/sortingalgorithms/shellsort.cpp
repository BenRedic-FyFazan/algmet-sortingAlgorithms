#include "./shellSort.hpp"
#include <iostream>
#include <cstdlib>

/*
 Example array: [1,5,2,9,3,6,4,7,8,10]
 gaplength = 5
 
 What the gap length does at each iteration is to effectively make comparisons
 with 'x' width. For example in the above array we will have the following comparisons:
 
 1 5 2 9 3 6 4 7 8 10
 --------------------
 1         6
   5         4
     2         7
       9         8
         3         10
 
 Then we do comparisons, and swap numbers where the rightmost integer is lower
 
 1         6
   4         5
     2         7
       8         9
         3         10
 
 which gives us the new array: 1 4 2 8 3 6 5 7 9 10
 then we divide the gap by 3 and redo it (since gap is now effectively 1
 it's just insertion sort).
 */
void shellsort(const int arrSize) {
    // Creating array for example
    std::vector<char> arr(arrSize+1);
    populateCharArray(arr, arrSize+1);
    int arrLen = int(arr.size());  // Array length
    
    /*
    Finding the gaplength.
    This is functionally the same as the for loop used in Frodes example:
    for (gap = 1;  gap <= arrLen / 9;  gap = (3 * gap) + 1);
    */
    int gap = 1;
    while (gap < arrLen/9) {
        gap = (3 * gap) + 1;
    }
    
    // h-sorting
    while (gap > 0)  {
        for (int i = gap + 1;  i < arrLen;  i++) {
            
            char tmp = arr[i];
            int j  = i;
            
            while (j > gap  &&  arr[j-gap] > tmp) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            std::cout << "I = " << i << ": Swapping '" << arr[j] << "' with '" << tmp << std::endl;
            arr[j] = tmp;
        }
        std::cout << std::endl << "Reducing gapsize!"  << std::endl;
        gap /= 3;
    }
    
    // Writes the result to console:
    std::cout << "Array after sorting: " << std::endl << "[" ;
    for (int i = 1; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size()-1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void displaySortingStep(const std::vector<char>& arr) {
    //std::cout << "Step: " << step++ << std::endl;
    std::cout << "[";
    for (int k = 1; k < arr.size(); k++) {
        std::cout << arr[k];
        if (k < arr.size() - 1) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
    std::cout << "Press enter to continue iteration..." << std::endl;
    std::cin.get();
}


void populateCharArray(std::vector<char>& arr, const int arrSize) {
    srand(0);
    arr[0] = ' ';                // sentinel key
    for (int i = 1;  i <= arrSize;  i++) {
        arr[i] =  static_cast <char> ('A' + (rand() % 26));
    }
}

