#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
    Given an array of integers nums and an integer k, 
    return the total number of subarrays whose XOR equals to k.


Examples:
Input : nums = [4, 2, 2, 6, 4], k = 6
Output : 4



Explanation : The subarrays having XOR of their elements as 6 are [4, 2],  [4, 2, 2, 6, 4], [2, 2, 6], and [6]
    */
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = 0;
    int x = 0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    for(int i=0;i<nums.size();i++){
        x = x ^ nums[i];
        int diff = x ^ k;
        if(mp.find(diff) != mp.end()) ans+=mp[diff];
        mp[x]++;
    }
    cout << ans << endl;
    return 0;
}
