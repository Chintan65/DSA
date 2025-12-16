#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n = 8;
    // vector<vector<char>> v(n, vector<char> (n));
    // for(int i=0;i<8;i++)
    //     for(int j=0;j<8;j++) cin >> v[i][j];
    // vector<int> d(2*n-1), a(2*n-1);
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++) cout << i+j << " ";
        cout << endl;
    }
    return 0;
}
