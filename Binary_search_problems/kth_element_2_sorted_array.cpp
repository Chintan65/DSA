#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if(n1 > n2) kthElement(b,a,k);
        int R = min(n1,k);
        int L = max(0,k - n2);
       // cout << L << " - " << R << endl;
        while(L <= R){
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            int M1 = L + (R - L) / 2;
            int M2 = k - M1;
            if(M1-1 >= 0) l1 = a[M1-1];
            if(M1 < n1) r1 = a[M1];
            if(M2-1 >= 0) l2 = b[M2-1];
            if(M2 < n2) r2 = b[M2];
            if(l1 <= r2 and l2 <= r1){
                return max(l1,l2);
            }
            else if(l1 > r2){
                R = M1 - 1;
            }
            else L = M1 + 1;
            

        }
        return 0;   
  }
};

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;
    
    //Create an instance of Solution class
    Solution solution;
    
    //Print the answer
    cout << "The " << k << "-th element of two sorted arrays is: "
         << solution.kthElement(a, b, k) << '\n';

    return 0;
}
