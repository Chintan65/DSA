#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // 2. Maximum length Subarray with given condition
/*
    given a binary array nums, return the maximum length
    of a subarray with an equal number of 0 and 1
*/
    vector<int> nums = {0,1,1,1,1,1,0,0,0};
    unordered_map<int,int> mp;
    int one = 0, zero = 0;
    int MaxLength = 0;
    mp[0] = -1;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == 0) zero++;
        else one++;
        int difference = zero - one;
        if(mp.find(difference) == mp.end()) mp[difference] = i;
        else MaxLength = max(MaxLength,i - mp[difference]);
    }
    cout << "max lenght would be - " << MaxLength << endl;
/*
Longest subarray with sum K
*/
    nums = {-1, 1, 1};
    int k = 1;
    int ans = 0;
    mp.clear();
    mp[0] = -1;
    int prefixsum = 0;
    for(int i=0;i<nums.size();i++){
        prefixsum += nums[i];
        int difference = prefixsum - k;
        if(mp.find(difference) == mp.end()) mp[prefixsum] = i;
        else ans = max(ans,i-mp[difference]);

    }
    cout << "Longest subarray with sum K is - " << ans << endl;
    return 0;

 /*
given an integer array nums and an integer x.
In one operation, you can either remove the leftmost
or the rightmost element from the array nums
and subtract its value from x
Return the minimum number of operations
to reduce x to exactly 0 if it is possible, otherwise, return -1.
*/

    nums = {3,2,20,1,1,3};
    int x = 10;
    int total = accumulate(nums.begin(),nums.end(),0);
    int target = total - x;
    cout << "ans is for minimum removels - ";
    if(target == 0) cout << nums.size() << endl;
    else{
        unordered_map<int,int> mp;
        mp[0] = -1;
        int prefixsum = 0;
        int maxLength = -1;
        for(int i=0;i<nums.size();i++){
            prefixsum += nums[i];
            int difference = prefixsum - target;
            if(mp.find(difference) != mp.end()){
                maxLength = max(maxLength,i - mp[difference]);
            }
            if(mp.find(prefixsum) == mp.end()) mp[prefixsum] = i;
        }
        if(maxLength == -1) cout << -1 << endl;
        else cout << nums.size() - maxLength << endl;
    }

    
}
