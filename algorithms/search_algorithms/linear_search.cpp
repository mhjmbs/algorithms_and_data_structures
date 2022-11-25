/*
Linear search finds a specific value in a sequence.
Time Complexity: O(n), where n is the number of values in the sequence.

The algorithms iterates through every element in the sequence.
When the element is found, it returns it's position as ans.
If ans = -1, there is no such value in the sequence.


Observations:

Can be used to find every ocurrence of the value, rather than the last or first.
*/

//Implementation examples:

#include <vector>

using namespace std;

//Looking for a value in an array.

int linearSearch(int target, vector<int>& array) {
    int ans = -1;

    for(int i = 0; i < array.size(); i++) {
        if(array[i] == target) {
            ans = i;
        }
    }

    return ans;
}