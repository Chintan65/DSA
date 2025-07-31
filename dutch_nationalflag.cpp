#include <bits/stdc++.h>
using namespace std;
int main(){
    // Dutch National Flag Problem
    // using three pointers (low, mid, high) Approch.
    // Given an array of 0s, 1s, and 2s, sort the array in a single pass
    // 0 to low-1 - 0s
    // low to mid-1 - 1s
    // mid to high - random or unsorted
    // high+1 to n-1 - 2s    
    // we need to sort unsoted par mid to high 
    vector<int> v = {0, 1, 2, 0, 1, 2, 1, 0, 2};
    int n = v.size();
    cout << "starting array - ";
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    int low =0, mid = 0, high = n-1;
    int i = 1;
    while(mid <= high){
        cout << "step nuber " << i++  << " mid - " << mid << " low - " << low << " high - " << high << " - ";
        if(v[mid] == 0){
            swap(v[low],v[mid]);
            low++;
            mid++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else{
            swap(v[high],v[mid]);
            high--;
        }
        // after swapping mid is not incremented because we need to check the swapped element
        for(auto &it:v) cout << it << " ";
        cout << endl;
        
    }
    cout << "ending erray - ";
    for(auto &it:v) cout << it << " ";
    cout << endl;

    return 0;
}