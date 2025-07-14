#include <bits/stdc++.h>
using namespace std;
int main(){
    // quick sort - means selecting a pivot element and partitioning the array into two halves
    // one with elements less than the pivot and one with elements greater than the pivot
    // and then recursively sorting each half.
    // It requires O(n log n) time complexity, but it is not a stable sort.
    // space complexity - O(log n) for the recursive stack space or O(n) if using a non-recursive implementation.
    // time complexity - O(n log n) on average, O(n^2) in the worst case
    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    cout << "unsorted array " << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;


    cout << "sorted final array" << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;





    /*
    quick sort vs merge sort  - 
    */



}