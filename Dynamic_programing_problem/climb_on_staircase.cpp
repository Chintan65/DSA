#include <bits/stdc++.h>
using namespace std;
int main(){
    // number of ways so climb staircase's top(N) using 1 or 2 steps
    int n = 25; // top
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
        cout << i << " - " << dp[i] << endl;
    }
    cout << dp[n] << endl; // number of ways to reach at top (nth level)
    // can be done in constante space also
    
    
}