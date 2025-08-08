#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {4,5,6,1,2,3};
    int n = v.size();
    for(int j = 0;j<n;j++){
        rotate(v.begin(),v.begin()+1,v.end());
        for(int i=0;i<n;i++) cout << v[i] << " ";
        cout << endl;
        int L = 0, R = n-1;
        int M;
        int ans = INT_MIN;
        while(L <= R){
            M = L + (R - L)/2;
           // cout << M << endl;
            if(M+1 >= n) {
                ans = n-1 ;
                break;
            }
            if(M-1 < 0){
                ans = 0;
                break;
            }
            if(v[M] > v[M+1] and v[M-1] > v[M] ) R = M - 1;
            else if(v[M] < v[M+1] and v[M-1] < v[M]) L = M+1;
            else {
                ans = M;
                break;
            }
        }
        cout << ans << endl;
    }
}