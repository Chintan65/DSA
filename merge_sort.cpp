#include <bits/stdc++.h>
using namespace std;
int main(){
    // Merge sort - is about dividing the array into two halves, sorting each half, and then merging the sorted halves.
    // It requires O(n log n) time complexity, but it is not a stable sort.
    // It is not an in-place sort, meaning it requires extra space for the temporary arrays used during the merge process.
    // Time complexity: O(n log n)
    // Space complexity: O(n)
    // The merge sort algorithm is a divide-and-conquer algorithm that works by recursively splitting the array into halves until each half contains a single element, and then merging those halves back together in sorted order.

    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    cout << "unsorted array " << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;



        for (int i = left; i <= right; ++i) {
            arr[i] = temp[i - left];
        }
    };

    merge(v, 0, n - 1);

    cout << "sorted final array" << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;

}