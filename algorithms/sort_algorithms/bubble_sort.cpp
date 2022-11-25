/*
Bubble Sort sorts a sequence of values in monotonic order.
Time Complexity: O(n^2), where n is the number of elements in the sequence.

The algorithm firstly compares values two by two, from the start of the sequence to the end.
If the value to the right should come before the value to the left, they are switched.
After getting to the end of the array, it is guaranteed that the last position is correct.
The same comparison process is repeated, but now from start to end-1, then start to end-2 and so on.
When start = end, it is guaranteed that every position is correct and the sequence is correctly sorted.
*/

//Implementation examples:

#include <vector>

using namespace std;

//Sorting an array of numbers in non-decreasing order

void bubbleSort(vector<int>& array) {
    int left = 0, right = array.size()-1;

    while(left < right) {
        for(int i = left; i < right; i++) {
            if(array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
            }
        }
        right--;
    }
}