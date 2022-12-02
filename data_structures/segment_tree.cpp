/*
Segment tree is a data structure good for querying for an operation in an array as long as:
    The operation is associative.
    The operations possesses a neutral element.
It also allows for efficient computing of results after a change in the array.
Time Complexity:
    Initializing the tree: O(n).
    Query: O(logn)
    Computing results after changes: O(logn)
    Where n is the amount of nodes in the tree.

Segtrees value's are stored in a common array, but it's indexing allows for usage as a tree.
A segtree for the sum of an interval for an array of size 8 looks like this:

Array:                  2 1 3 6 5 8 4 2
Array's indexes:        0 1 2 3 4 5 6 7

Segtree:

                       31
                   12      19
                 3   9   13  6
                2 1 3 6 5 8 4 2

Segtree's array indexes:

                        0
                   1          2
                 3   4     5     6
                7 8 9 10 11 12 13 14

Noticeably:
    The child's of node of index n are indexed 2*n+1 and 2*n+2.
    The first index of the leaf's row is array.size()-1.

The segtree is a perfect binary tree, so every non-leaf node has exactly two childs.
This means the leaf row of the tree can't be exactly the initial array, because it's size may not be a power of two.
The remaining nodes are set to the neutral element of the operation we want our segtree to efficiently compute in an interval.
This way they don't interfere with other results. 

For it's proper usage, segtree requires for 3 basic functions: init, set and query.

Init:
    The init function initializes the segtree array, it must be called before everythin else and only once.
    It finds the smallest power of two bigger than the initial array and sets the segtree array that size.
    For an initial array of size n, all n initial positions of the leaf's row are set equal to the initial array.
    The remaining elements are set as the neutral element of this segtree's operation.
    All non-leaf nodes are set to be the result of the operation of it's two children.
Set:
    The set function makes changes to a leaf node the segtree array and updates all it's parents.
Query:
    The query function returns the result of the operation in a specific interval of the array.

All three functions may be recursively or iteratively implemented.
The init and set iterative functions are faster and more easily implemented than their recursive alternatives.
As for the query, the iterative implementation is really complex, so the recursive is a better choice, even being slower.

The funcionts are implemented using the following property:
    The child's of node of index n are indexed 2*n+1 and 2*n+2.

Init and set are implemented straight-fowardly from the property above, with a bottom up approach.

Query is implemented with a top down recursive approach, with the following cases:
If current node perfectly represent any part from the desired interval, return it's value.
If it perfectly does not represent any part from the desired interval, return the neutral element of the operation.
If it partially represents the desired interval, return query(2*n+1) operation query(2*n+2).

The intervals represented by each node are calculated as query is called.
    Index 0 represents the whole leaf row.
    Index 1 represents [0, (leafRowSize-1)/2]
    Index 2 represents [(leafRowSize-1)/2 + 1 , (leafRowSize-1)]
And this logic goes on for every node.
*/



//Implementation Examples:

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

//Segtree for the sum of an interval

struct segtree {
    int lrStart;
    int lrSize = 1;
    vector<ll> st;

    segtree(vector<int>& a) {
        setSize(a.size());
        lrStart = st.size() - lrSize;

        for(int i = lrStart; i - lrStart < a.size(); i++) {
            st[i] = a[i - lrStart];
        }

        for(int i = lrStart-1; i >= 0; i--) {
            st[i] = st[2*i+1] + st[2*i+2];
        }
    }

    void setSize(int initSize) {
        while(lrSize < initSize) {
            lrSize *= 2;
        }

        st.resize(2*lrSize - 1, 0);
    }

    void set(int i, int v) {
        i = lrStart + i;
        st[i] = v;

        while(i > 0) {
            if(i % 2 == 0) {
                st[(i-2)/2] = st[i] + st[i-1];
                i = (i-2)/2;
            }else {
                st[(i-1)/2] = st[i] + st[i+1];
                i = (i-1)/2;
            }
        }
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) {
            rx = lrSize-1;
        }

        if(l <= lx && rx <= r) {
            return st[i];
        }else if(rx < l || r < lx) {
            return 0;
        }else {
            int m = lx + (rx-lx)/2;
            return query(l, r, lx, m, 2*i+1) + query(l, r, m+1, rx, 2*i+2);
        }
    }
};

//Segtree for the minimum in an interval

struct segtree {
    int lrStart;
    int lrSize = 1;
    vector<int> st;

    segtree(vector<int>& a) {
        setSize(a.size());
        lrStart = st.size() - lrSize;

        for(int i = lrStart; i - lrStart < a.size(); i++) {
            st[i] = a[i - lrStart];
        }

        for(int i = lrStart-1; i >= 0; i--) {
            st[i] = min(st[2*i+1], st[2*i+2]);
        }
    }

    void setSize(int initSize) {
        while(lrSize < initSize) {
            lrSize *= 2;
        }

        st.resize(2*lrSize - 1, INT_MAX);
    }

    void set(int i, int v) {
        i = lrStart + i;
        st[i] = v;

        while(i > 0) {
            if(i % 2 == 0) {
                st[(i-2)/2] = min(st[i], st[i-1]);
                i = (i-2)/2;
            }else {
                st[(i-1)/2] = min(st[i], st[i+1]);
                i = (i-1)/2;
            }
        }
    }

    int query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) {
            rx = lrSize-1;
        }

        if(l <= lx && rx <= r) {
            return st[i];
        }else if(rx < l || r < lx) {
            return INT_MAX;
        }else {
            int m = lx + (rx-lx)/2;
            return min(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
        }
    }
};
