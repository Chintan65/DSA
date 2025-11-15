#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
/*
    c -> column
    d -> diagonal
    a -> anti diagonal
    diagonal index = row - col + (n-1)
    anti diagonal index = row + col 
    row - col = for all elements in a diagonal the value of row - col is constant
    row + col = for all elements in an anti diagonal the value of row + col is constant 
    in diagonal we add n-1 to make it non negative
*/
    void go(int i,int n,int &c,int &d,int &a,vector<vector<string>> &ans,vector<string> &v){
        if(i == n){
            ans.push_back(v);
            return;
        }
        for(int j=0;j<n;j++){
            if(c & (1 << j) or d & (1 << (i - j+n-1)) or a & (1 << (i+j))) continue;
            else{
                c = c | (1 << j);
                d = d | (1 << (i - j + n - 1));
                a = a | (1 << (i+j));
                v[i][j] = 'Q';
                go(i+1,n,c,d,a,ans,v);
                v[i][j] = '.';
                c = c & ~(1 << j);
                d = d & ~(1 << (i - j + n - 1));
                a = a & ~(1 << (i+j));
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        int c = 0,d = 0,a = 0;
        vector<vector<string>> ans;
        vector<string> v(n, string(n,'.'));
        go(0,n,c,d,a,ans,v);
        return ans;    
    }
};
int main() {
    Solution solution;
    int n = 5; 
    vector<vector<string>> solutions = solution.solveNQueens(n);
    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}