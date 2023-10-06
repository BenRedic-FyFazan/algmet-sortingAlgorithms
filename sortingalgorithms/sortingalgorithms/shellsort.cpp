#include "./shellSort.hpp"
#include <iostream>
#include <cstdlib>

void shellSort(std::vector<char>& arr) {
    
    int gap = 1;
    int j;
    char verdi;

    
    // Finding the gaplength
    for (gap = 1;  gap <= arr.size() / 9;  gap = (3 * gap) + 1);
    
    while (gap > 0)  {
        for (int i = gap + 1;  i < arr.size();  i++) {
            verdi = arr[i];
            j  = i;
            
            while (j > gap  &&  arr[j-gap] > verdi) {
                arr[j] = arr[j-gap];
                j -= gap;
            }
            arr[j] = verdi;
        }
        gap /= 3;
    }
}
