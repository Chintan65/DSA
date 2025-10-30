#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Prefix Sum + Hashmap Approach
    //We can apply this approach in problems related to Subarrays, problems where we are asked to
// Count the subarrays with some condition
// Find Maximum Length Subarray with some condition
// Check if subarray exists with some given condition
// Mainly the problems dealing with Subarray sum .
// Now you might wonder that what is stopping you from using Sliding window approach for such problems
// Sliding window is only applicable when we know for sure if the prefixsum is an increasing or decreasing function
// So basically for subarray related problems Brute Force method takes O(n^2) time to process each subarray + extra time in processing .
// But with this approach only O(n) time is taken 


// Condition : Subarrays that have a sum divisible by k. 
// Negative values ALLOWED in Input
// in devisibility always remember that we need to measure in term of % k 
// and need to make thing positive by ading k again in it 
/*

Two prefix sums having the same remainder 
when divided by k form a subarray whose sum is divisible by k.

*/
    vector<int> v = {4,5,0,-2,-3,1};
    int k = 5;
    unordered_map<int,int> mp;
    int sum = 0;
    int ans = 0;
    mp[0] = 1;
    for(int i=0;i<v.size();i++){
        sum = (sum+v[i])%k;
        if(sum < 0) sum += k;
        ans += mp[sum];
        mp[sum]++;
    } 
    cout << ans << endl;

    // 523. Continuous Subarray Sum
/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
*/
    vector<int> nums = {23,2,4,6,7};
    k = 6;
    unordered_map<int,int> mp2;
    sum = 0;
    mp2[0] = -1; // to handle the case when subarray starts
    bool found = false;
    for(int i=0;i<nums.size();i++){
        sum = (sum + nums[i]) % k;
        if(sum < 0) sum += k;
        if(mp2.find(sum) != mp2.end()){
            if(i - mp2[sum] >= 2){
                found = true;
                break;
            }
        }else{
            mp2[sum] = i;
        }
    }
    cout << (found ? "true" : "false") << endl;
    return 0;
}
