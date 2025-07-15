#include <bits/stdc++.h>
using namespace std;
int pi(vector<int>& v,int l,int h){
    int i = l;
    int j = h;
    int pivot = v[l]; // Choosing the first element as pivot
    while(i < j){
        while(v[i] <= pivot and i < h) i++; // Increment i until we find an element greater than pivot
        while(v[j] > pivot) j--; // Decrement j until we find an element less than or equal to pivot
        if(i < j ) swap(v[i], v[j]); // Swap elements if i is less than j   
    }
    swap(v[l],v[j]); // Place the pivot in its correct position
    return j; // Return the index of the pivot

}
void qs(vector<int>& v, int l, int h){
    if(l<h){
        int partitionIndex = pi(v,l,h);
        qs(v, l, partitionIndex - 1); // Recursively sort elements before partition
        qs(v, partitionIndex + 1, h); // Recursively sort elements after partition
    }
}
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

    qs(v,0,n-1);


    cout << "sorted final array" << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;








}