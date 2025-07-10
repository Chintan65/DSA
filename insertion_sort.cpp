#include <bits/stdc++.h>
using namespace std;
int main(){
    // Insertion sort - is about taking an element and inserting it into the correct position in the sorted part of the array.
    // It requires generally n^2 time complexity, but it is a stable sort.
    // stable sort - it maintains the relative order of equal elements in the sorted array.
    // For example, if two elements are equal, their order will be preserved in the sorted
    // insertion sort is an in-place sort, meaning it does not require any extra space.
    // Time complexity: O(n^2)
    // Time complexity : best case - O(n)
    // Space complexity: O(1)
    // The best case occurs when the array is already sorted, and the algorithm only needs to make a single pass through the array.
    
    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    cout << "unsorted array " << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    cout << "insertion sort calculation" << endl;
    for(int i = 1; i < n; i++){
        int key = v[i];
        int j = i - 1;
        // Move elements of v[0..i-1], that are greater than key, to one position ahead of their current position
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
        cout << "step number - " << i << " : - ";
        for(int k=0;k<n;k++) cout << v[k] << " ";
        cout << endl;
    }   
    cout << "sorted final array" << endl;
    for(int i=0;i<n;i++) cout << v[i] <<  " ";
    cout << endl;
}