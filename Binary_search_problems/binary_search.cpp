#include <bits/stdc++.h>
using namespace std;
int LowerBound(vector<int> v,int n){

    // first element which is >= n
    int L = 0, R = v.size() - 1;
    int ans = v.size();
    int M;
    while(L <= R){
        M = L + (R - L) / 2;
        if(v[M] >= n) {
            ans = M;
            R = M - 1;
        }
        else L = M+1;
    } 
    return ans;
}
bool Issqr(int n){
    int L = 1, R = n;
    while(L <= R){
        int M = L + (R - L)/2;
        int cal = M*M;
        if(cal == n) return true;
        else if(cal < n) L = M+1;
        else R = M-1;
    }
    return false;
}
int main(){
    // binary search
    vector<int> v = {64, 25, 12, 22, 11};
    sort(v.begin(),v.end());
    int n = v.size();
    // L = start, R = end, M = mid,
    // M = L + floor((R - L)/2)
    // N - N/2 - N/4 - N/8 - N/16 .....  
    // Time complexity - Log2(N)
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    int L = 0, R = n-1;
    int ans = -1;
    int target = 25;
    while( L <= R){
        int M = L + (R - L)/2;\
        if(v[M] == target){
            ans = M;
            break;
        }
        if(v[M] < target) L = M + 1;
        else R = M - 1;
    }
    cout <<"position of target - "<< target << " is - " <<ans  << endl;
    for(int i=0;i<n;i++){
        cout << "is - " << v[i] << " prefect squre - " << (Issqr(v[i])?" Yes ": " No ") << endl;
    }
    target = 24;
    cout << "Lower bound of element "<< target << " is -  " << v[LowerBound(v,target)] << " checking with build in function - " << *lower_bound(v.begin(),v.end(),target) << endl;

}


// summary
// 1. Binary search is used to find an element in a sorted array.
// 2. Real value 
// 3. the last/first element which satisfies the condition
// 4. Time complexity - O(log n)
// 5. Space complexity - O(1)
// 6. Lower bound - first element which is >= n
// 7. Upper bound - first element which is > n