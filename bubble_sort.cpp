#include <bits/stdc++.h>
using namespace std;
int main(){
    // Bubble sort - is about comparing adjacent elements and swapping them if they are in the wrong order
    // It requires generally n^2 time complexity, but it is a stable sort.
    // stable sort - it maintains the relative order of equal elements in the sorted array.
    // For example, if two elements are equal, their order will be preserved in the sorted
    // array as they were in the original array.
    // It is an in-place sort, meaning it does not require any extra space. 
    // Time complexity: O(n^2)
    // Time complexity : best case - O(n)
    // Space complexity: O(1)

    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    cout << "unsorted array " << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    cout << "bubble sort calculation" << endl;
    bool sp;
    for(int i = n-1;i > 0;i--){
        sp = true;
        for(int j=0;j<i;j++){
            if(v[j] > v[j+1]){
                swap(v[j],v[j+1]);
                sp = false;
            }
        }
        if(sp) break;
        cout << "step number - " << n - (i) << " : - ";
        for(int i=0;i<n;i++) cout << v[i] << " ";
        cout << endl;

    }
    cout << "sorted final erray" << endl;
    for(int i=0;i<n;i++) cout << v[i] <<  " ";
    cout << endl;


}