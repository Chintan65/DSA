#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // You have n coins with positive integer values. 
    // What is the smallest sum you cannot create using a subset of the coins?
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int s = 1;
    for(int i=0;i<n;i++){
        if(v[i] > s) break;
        s += v[i];
    }
    cout << s << endl;
    return 0;
}
