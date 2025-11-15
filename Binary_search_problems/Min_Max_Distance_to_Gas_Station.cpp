#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        long double R = INT_MIN;
        for(int i=1;i<n;i++) {
            if(R < (long double) arr[i] - arr[i-1] ) R = (long double)arr[i] - arr[i-1];
        }
        long double L = (long double) (arr[arr.size() - 1] - arr[0]) / (arr.size() + k);
        long double M = R;
        while(R - L >= 1e-6){
            M = L + (R - L) / 2;
            int cnt = 0;
            //cout << L << " " << R << " " << M << endl;
            for(int i=1;i<n;i++){
                long double d = arr[i] - arr[i-1];
                int need = ceil((long double) d / M) - 1;
                cnt = cnt + need;
            }
            if(cnt <= k) R = M;
            else L = M;
        }
        return R;
       
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    // Create an instance of the Solution class
    Solution sol;

    // Call the minimiseMaxDistance method and print the result
    long double ans = sol.minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}