#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    // used basically when things are sorted
    // or we sort to obteain solution when time complexity O(n log n) is acceptable
    // for example need to finda two pair in array which sum to a given number
    int target = 23;
    cout << "target sum is - " << target << endl;
    int L = 0, R = n-1;
    // we can  copy array to another array and sort it or we can map them with index
    // and then can use two pointer technique
    vector<int> vv = v;
    sort(vv.begin(),vv.end());
    int sum;

    while(L < R){
        sum = vv[L] + vv[R];
        if(sum == target){
            break; // found the pair
        }
        else if(sum < target) L++;
        else R--;
    }
    if(L > R) cout << "No pair found with sum " << target << endl;
    else {
        int first,second;
        for(int i=0;i<n;i++){
            if(v[i] == vv[L]) first = i; // find the index of first element
            if(v[i] == vv[R]) second = i; // find the index of second element
        }
        cout << "Pair found with sum " << target << " is - " << v[first] << " and " << v[second] << endl;
        cout << "Their index in original array is - " << first << " and " << second << endl;
    }

    // Time complexity - O(n log n) for sorting and O(n) for two pointer technique
    // Space complexity - O(n) for storing the sorted array
    
}
