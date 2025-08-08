#include <bits/stdc++.h>
using namespace std;
int main(){
    // need to go from top-left on grid to bottom-right 

    // with only allowed to move right and bottom
    vector<vector<int>> grid = {
        {3, 2, 1, 4},
        {2, 1, 3, 1},
        {1, 2, 7, 5}
    };
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 and j == 0) dp[i][j] = grid[i][j];
            else if(i == 0) dp[i][j] = grid[i][j] + dp[i][j-1];
            else if(j == 0) dp[i][j] = grid[i][j] + dp[i-1][j];
            else dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Minimum path sum: " << dp[n-1][m-1] << endl;




    

}