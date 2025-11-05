#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int L = 1;
    int R = accumulate(v.begin(),v.end(),0LL);

    return 0;
}
