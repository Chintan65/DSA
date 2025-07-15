#include <bits/stdc++.h>
using namespace std;
int main(){
    // linear search - means checking each element of the array one by one until the desired element is found.
    // It requires O(n) time complexity, where n is the number of elements in the array.
    // space complexity - O(1) as it does not require any additional space.
    // time complexity - O(n) in the worst case when the element is not present in the array.

    vector<int> v = {64, 25, 12, 22, 11};
    int n = v.size();
    int target  = 22; // Element to be searched
    int ans = -1; // Variable to store the index of the found element else -1 if not found
    for(int i=0;i<n;i++){
        if(v[i] == target){
            ans = i;
            break; 
        }
    }
    cout << "Element " << target << " found at index: " << ans << endl;
    return 0;   
}