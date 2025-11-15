#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<string> findPath(vector<vector<int> > &grid) {
        vector<string> ans;
        string s = "";
        int n = grid.size();
        vector<vector<bool>> v(n, vector<bool> (n,0));
        if(grid[0][0] == 1){
            v[0][0] = 1;
            go(0,0,ans,s,grid,v,n);
        }
        return ans;
    }
    private:
    void go(int i, int j,vector<string> &ans,string &s, vector<vector<int>> &grid,vector<vector<bool>> &v,int n){
        if(i == n-1 and j == n-1){
            ans.push_back(s);
            return;
        }
        v[i][j] = 1;
        if(i+1 < n and grid[i+1][j] == 1 and v[i+1][j] == 0) {
            s.push_back('D');
            go(i+1,j,ans,s,grid,v,n); 
            s.pop_back();
        }
        if(i-1 >= 0 and grid[i-1][j] == 1 and v[i-1][j] == 0){
            s.push_back('U');
            go(i-1,j,ans,s,grid,v,n);
            s.pop_back();
        }
        if(j+1 < n and grid[i][j+1] == 1 and v[i][j+1] == 0){
            s.push_back('R');
            go(i,j+1,ans,s,grid,v,n);
            s.pop_back();
        }
        if(j-1 >= 0 and grid[i][j-1] == 1 and v[i][j-1] == 0){
            s.push_back('L');
            go(i,j-1,ans,s,grid,v,n);
            s.pop_back();
        }
        v[i][j] = 0;
        return;
        

    }
};
int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };
    Solution sol;
    vector<string> paths = sol.findPath(grid);
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}