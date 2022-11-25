/*
Bubble Sort sorts a sequence of values into a monotonic ordering.
Time Complexity: O(n^2), where n is the number of elements in the sequence.

The algorithm firstly compares values two by two, from the start of the sequence to the end.
If the value to the right should come before the value to the left, they are switched.
After getting to the end of the list, it is guaranteed that the last position is correct.
The same comparison process is repeated, but now from start to end-1, then start to end-2 and so on.
When start = end, it is guaranteed that every position is correct and the sequence is correctly sorted.
*/

//Implementation examples:

#include <vector>

using namespace std;

//Sorting a list of numbers into non-decreasing order

void bubbleSort(vector<int>& list) {
    int left = 0, right = list.size()-1;

    while(left < right) {
        for(int i = left; i < right; i++) {
            if(list[i] > list[i+1]) {
                int tmp = list[i];
                list[i] = list[i+1];
                list[i+1] = tmp;
            }
        }
        right--;
    }
}