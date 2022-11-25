/*
Binary search finds a specific value in a monotonic sequence of values.
Complexity: O(logn), where n is the number of values in the sequence.

To look for this value, firstly de algorithm needs the left and right extremes of the monotonic sequence.
Then, it retrieves the middle element of the sequence, and compares it to a target value.
    Possible desired values:
        first value equal to target.
        last value equal to target.
        first value less-equal to target.
        first value greater than target.
        ...
According to the monotonic pattern of the sequence, it's possible to know if the desired value is to the left or to the right of middle.
We halve the searching area, remaining only the half that the desired value is/might be.


Observations:

The desired value might not be in the sequence. In that case, if ans = -1 and search range = 0, it wasn't found.

The first value greater or equal to a target in a monotonic sequence is called lowerbound.
The first value greater to a target in a monotonic sequence is called upperbound.

Binary searches that find the upperbound and lowerbound in a random access permitting data structure are already implemented in c++:

Iterator lower_bound (Iterator first, Iterator last, const val) 
Iterator upper_bound (Iterator first, Iterator last, const val)

If the value is not found, the end iterator of given data strucure is returned.
*/

//Implementation examples:

//Looking for a value equal to target.

#include <vector>

using namespace std;

int binarySearch1(int target, vector<int>& list) {
    int left = 0, right = list.size()-1, ans = -1;

    while(left <= right) {
        int middle = left + (right - left)/2;

        if(target < list[middle]) {
            right = middle - 1;
        }else if(list[middle] < target){
            left = middle + 1;
        }else {
            ans = middle;
            break;
        }
    }

    return ans;
}

//Looking for the first value strictly smaller than target.

int binarySearch2(int target, vector<int>& list) {
    int left = 0, right = list.size()-1, ans = -1;

    while(left <= right) {
        int middle = left + (right - left)/2;

        if(target <= list[middle]) {
            right = middle - 1;
        }else if(list[middle] < target){
            right = middle - 1;
            ans = middle;
        }
    }

    return ans;
}

//Looking for the first value greater or equal to target.

int binarySearch2(int target, vector<int>& list) {
    int left = 0, right = list.size()-1, ans = -1;

    while(left <= right) {
        int middle = left + (right - left)/2;

        if(target <= list[middle]) {
            right = middle - 1;
            ans = middle;
        }else if(list[middle] < target){
            right = middle + 1;
        }
    }

    return ans;
}