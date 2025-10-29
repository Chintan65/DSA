#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15; // target sum
    unordered_map<int,int> mp;
    int ans = 0;
    int sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k) ans = max(ans,i+1);
        int tp = sum - k;
        if(mp.find(tp) != mp.end()){
            ans = max(ans,i - mp[tp]);
        }
        if(mp.find(sum) == mp.end()) mp[sum] = i;

    }
    cout << ans << endl;
    return 0;
}
