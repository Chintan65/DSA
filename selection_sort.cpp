#include <bits/stdc++.h>
using namespace std;
int main(){
    // selection sort - is about finding the minimum element in the array and swapping it with the first element
    // then finding the second minimum element and swapping it with the second element, and so on.
    // it requre genrally n^2 time complexity, but it is not stable sort.
    // it is in-place sort, meaning it does not require any extra space.
    // time complexity: O(n^2)
    // space complexity: O(1)
    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    cout << "unsorted array " << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    cout << "selection sort calculation" << endl;   
    for(int i=0;i<n-1;i++){ // outer loop for each element till n-2 as last element will be sorted automatically
        int mn = i; // assume the minimum element is at index i
        for(int j=i;j<n;j++){ // inner loop to find the minimum element in the unsorted part of the array
            if(v[j] < v[mn]){ // if the current element is less than the minimum element found so far
                mn = j; // update the index of the minimum element
            }
        }
        swap(v[i],v[mn]); // swap the minimum element with the first element of the unsorted part

        cout << "step " << i << " : ";
        for(int k=0;k<n;k++) cout << v[k] << " "; // print the array at each step
        cout << endl;

    }
    cout << "sorted array " << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl; 
}
