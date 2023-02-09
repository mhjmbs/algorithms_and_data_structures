/*
Segment tree is a data structure that, given a binary associative function f with neutral element:
    Calculates the value of f in an interval [l,r].
    Updates the value of a given index i.

Time Complexity:
    Initializing the tree: O(n).
    Query: O(logn)
    Updates: O(logn)
    Where n is the number of nodes in the tree.

In sake of simplicity of understading, let's consider a segment tree for the sum of an interval.

Lets consider the following array a:

Array:                  2 1 3 6 5 8 4 2
Array's indexes:        0 1 2 3 4 5 6 7

Segment Tree sums the numbers two by two, storing the result of each sum as the parent of the two summed numbers.
Then, it sums the previous results two by two, storing the new result as the parent of the two summed results.
This goes on until we're left with one result: the sum of the entire array.

For the array a, this is visualized as following:

a's sum segtree:

                       31
                   12      19
                 3   9   13  6
                2 1 3 6 5 8 4 2

All this information is stored in a single array in the following manner:

a's sum segtree array indexes:

                        0
                   1          2
                 3   4     5     6
                7 8 9 10 11 12 13 14

This convenient indexing discards the need for the storage of any aditional information for the tree traversal, given that, for a non-leaf node in index i:
    The node at 2*i+1 is it's left child.
    The node at 2*i+2 is it's right child.

Notice that, as every node has two childs except for leafs, a segment tree is a perfect binary tree.
Given that, for a perfect binary tree to be possible, every level, from the root level to the leaf level, must have a power of two number of elements.
As the original array's number of elements may not be a power of two, these remaining spots may interfere in the overall result of some node.
This can be solved by filling the extra spots of the leaf row with the neutral element of the operation being considered.

Segtree's functionality is separated in three functions:

Init:
    The init function takes an array and builds it's segtree for some operation.
        It finds the smallest power of two x bigger than the initial array and sets the segtree array size to be 2x-1.
        For an initial array of size n, all n initial positions of the leaf's row are set equal to the initial array. *The index of the first element in the leaf row is the array size - x.
        The remaining elements are set as the neutral element of this segtree's operation.
        All non-leaf nodes are set to be the result of the operation of it's two children.

Update:
    The update function makes changes to a leaf node the segtree array and updates all it's parents, navigating through the indexes by their mentioned properties.
Query:
    The query function returns the result of the operation given a specific interval [l,r] of the array.

All three functions may be recursively or iteratively implemented.
In the following examples, Init and Update are iterative, whilst Query is recursive.
*/



//Implementation Examples:

#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pii = pair<int,int>;

//Segtree for the sum of values in an interval

struct SegTree {
    vector<ll> seg;
    int lr_start; //lr refers to the last row of the tree, i.e, the row composed by all it's leafs.
    int lr_size = 1;

    SegTree(vector<int> &a) {
        setSize(a.size());

        lr_start = seg.size() - lr_size;

        for(int i = 0; i < a.size(); i++) {
            seg[lr_start + i] = a[i];
        }

        for(int i = lr_start-1; 0 <= i; i--) {
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    void setSize(int array_size) {
        while(lr_size < array_size) lr_size *= 2;
        seg.resize(2*lr_size - 1, 0); //all positions intialized to the operation's neutral element.
    }

    void set(int i, int v) {
        i = lr_start + i;
        seg[i] = v;

        while(i > 0) {
            if(i % 2 == 0) i = (i-2)/2;
            else i = (i-1)/2;
            seg[i] = seg[2*i+1] + seg[2*i+2];
        }
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        int m = (lx+rx)/2;

        if(rx < l || r < lx) return 0;
        if(l <= lx && rx <= r) return seg[i];
        return query(l, r, lx, m, 2*i+1) + query(l, r, m+1, rx, 2*i+2);
    }
};

//Segtree for the minimum value in an interval

struct SegTree {
    vector<int> seg;
    int lr_start; //lr refers to the last row of the tree, i.e, the row composed by all it's leafs.
    int lr_size = 1;

    SegTree(vector<int> &a) {
        setSize(a.size());

        lr_start = seg.size() - lr_size;

        for(int i = 0; i < a.size(); i++) {
            seg[lr_start + i] = a[i];
        }

        for(int i = lr_start-1; 0 <= i; i--) {
            seg[i] = min(seg[2*i+1], seg[2*i+2]);
        }
    }

    void setSize(int array_size) {
        while(lr_size < array_size) lr_size *= 2;
        seg.resize(2*lr_size - 1, INT_MAX); //all positions intialized to the operation's neutral element.
    }

    void set(int i, int v) {
        i = lr_start + i;
        seg[i] = v;

        while(i > 0) {
            if(i % 2 == 0) i = (i-2)/2;
            else i = (i-1)/2;
            seg[i] = min(seg[2*i+1], seg[2*i+2]);
        }
    }

    ll query(int l, int r, int lx = 0, int rx = -1, int i = 0) {
        if(rx == -1) rx = lr_size-1;

        int m = (lx+rx)/2;

        if(rx < l || r < lx) return 0;
        if(l <= lx && rx <= r) return seg[i];
        return min(query(l, r, lx, m, 2*i+1), query(l, r, m+1, rx, 2*i+2));
    }
};