/*
Merge sort sorts a sequence of values in monotonic order.
Time complexity: O(nlogn), where n is the number of elements in the sequence.

The algorithm recusively acesses each half of the sequence.
When a half of size 1 is reached, it's already sorted.
After sorting two halves, they're merged into an auxiliar array.
The merge is done using two pointers, each iterating through one half.
The smallest element being pointed to is added to the auxiliar array and it's pointer is incremented.
If one of the pointers is pointing outside it's respective half, then the element in the other half is added.
The final merged array is correctly sorted.
*/

//Implementation examples:

#include <vector>

using namespace std;

//Sorting an array of integers in non-decreasing order.

void merge(int left, int middle, int right, vector<int>& array) {
    int half1Index = left, half2Index = middle+1;
    vector<int> aux(array.size());

    for(int& x : aux) {
        if((half2Index > right || array[half1Index] <= array[half2Index]) && half1Index < middle+1) {
            x = array[half1Index];
            half1Index++;
        }else {
            x = array[half2Index];
            half2Index++;
        }
    }

    for(int i = left, j = 0; i <= right; i++, j++) {
        array[i] = aux[j];
    }
}

void mergeSort(int left, int right, vector<int>& array) {
    if(left < right) {
        int middle = left + (right - left)/2;
        mergeSort(left, middle, array);
        mergeSort(middle+1, right, array);
        merge(left, middle, right, array);
    }
}