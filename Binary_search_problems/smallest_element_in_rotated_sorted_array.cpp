#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {6, 7, 9, 15, 19, 2, 3};
    int n = v.size();
    // binary search - we need to find the boundary that differentiate thats main logic

    // for example 2 3 4 5 6 7 - finda lower bound of 4 that means
    // >= 4 so if we differentiate array on basis of that
    // 2 3 4 5 6 7
    // F F T T T T
    // so basically we are finding first true / last false in that array thats the boundary

    // 6 7 9 15 19 2 3
    // we can compare with first and last element - and can define T F
    // if i compare with first element and assume that greter and equal are T and other are
    for (int j = 0; j < n; j++){
        rotate(v.begin(), v.begin() + 1, v.end());
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
        int ans = -1;
        int L = 0, R = n - 1;
        while (L <= R){
            int M = L + (R - L) / 2;
            if (v[M] >= v[0]){
                ans = M;
                L = M + 1;
            }
            else{
                R = M - 1;
            }
        }
        cout << "smallest element index - " << ((ans+1 == n)?0:ans+1) << endl;
    }
}