#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& v, int l, int m, int h){
    vector<int> tp;
    int left = l;
    int right = m+1;
    while(left <=m and right <= h){
        if(v[left] <= v[right]){
            tp.push_back(v[left]);
            left++;
        }
        else {
            tp.push_back(v[right]);
            right++;
        }
    }
    while(left<=m){
        tp.push_back(v[left]);
        left++;
    }
    while(right<=h){
        tp.push_back(v[right]);
        right++;
    }
    for(int i=l;i <= h;i++) {
        v[i] = tp[i - l];
    }
}
void ms(vector<int>& v,int l,int h){
    if(l>=h) return;
    int m = (l+h)/2;
    ms(v,l,m);
    ms(v,m+1,h);
    merge(v,l,m,h);
}
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
    ms(v,0,n-1);

    cout << "sorted final array" << endl;
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;

}