/*
Quick sort sorts a sequence of values in monotonic order.
Time Complexity: O(n^2), where n is the number of elements in the sequence.

The algorithm chooses a pivot(the last element the way i do it) and looks for elements that should come before it.
If it finds one, it's swapped with the first element of the array.
If it finds another one, it's swapped with the second element of the array, and so on.
After doing this for every element on the sequence, the last position to have it's value swapped by a value that should come before pivot is the pivot itself.
Now, every value to the left of pivot should be to the left of it, and we can say the same for every value on the right.
The same steps above are called recursively for the values on the left of pivot and to the right of pivot until left = right.
At the end, every value to the left or right of any other value should be there, so the array is ordered.
*/

#include <vector>

using namespace std;

//Implementation examples:

//Sorting an array of integers in non-decreasing order.

int partition(int left, int right, vector<int>& array) {
    int pivot = array[right], lastLeft = -1;

    for(int i = 0; i <= right; i++) {
        if(array[i] <= array[right]) {
            lastLeft++;
            swap(array[i], array[lastLeft]);
        }
    }

    return lastLeft;
}

void quickSort(int left, int right, vector<int>& array) {
    if(left < right) {
        int lastPivot = partition(left, right, array);
        quickSort(left, lastPivot-1, array);
        quickSort(lastPivot+1, right, array);
    }
}