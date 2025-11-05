#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    map<int,int> mp;
    int start = 0, maxlen = 0;
    for(int i=0;i<n;i++){
        if(mp.count(v[i]) and mp[v[i]] >= start){
            start = mp[v[i]] + 1;
        }
        maxlen = max(maxlen,i - start +1);
        mp[v[i]] = i;
    }
    cout << maxlen << endl;
    return 0;
}
