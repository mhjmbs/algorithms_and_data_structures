/*
Counting sort sorts a sequence of values, whose value's range is known, in monotonic order.
Time Complexity: O(n + k), where n is the number of values in the sequence and k is the number of values in the range.

The algorithm starts by iterating through the sequence and saving the frequency of each value in the range.
It does this by using an array. Each number in the array represents the frequency of left+index in the sequence.
Then, by iterating through the array the numbers in the sequence can be retrieved in monotonic ordering.

Observations:

As an array of size = number of possible values is allocated, counting sort is terrible when the range of possible values is large.
*/

//Implementation examples:

#include <vector>

using namespace std;

//Sorting an array of integers in non-deacreasing order.

void countingSort(int left, int right, vector<int>& array) {
    vector<int> freq(right-left+1, 0);

    for(int value : array) {
        freq[value]++;
    }

    int arrayIndex = 0;

    for(int i = 0; i < freq.size(); i++) {
        while(freq[i] > 0) {
            array[arrayIndex] = left+i;
            freq[i]--;
            arrayIndex++;
        }
    }

}