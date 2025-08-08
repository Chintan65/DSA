#include <bits/stdc++.h>
using namespace std;
int main(){
    // Need to find number of was to reach top (n) of staircase in atmost k steps 
    // can take 2 type of steps 1 and 2
    int n = 10;
    int k = 6;
    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    dp[0][0] = 0;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = dp[i-1][j-1] + dp[i-2][j-1];
        }
    } 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    int ans = 0;
    for(int i=1;i<=k;i++) ans+= dp[n][i];
    cout << ans << endl; // number of ways to reach at top (nth level)



}