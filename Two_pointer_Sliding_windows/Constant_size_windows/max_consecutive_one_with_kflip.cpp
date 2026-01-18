#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // problem: Max Consecutive Ones III
    // Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int left = 0;
    int zeroCount = 0;
    int maxLength = 0;
    for(int right = 0; right < nums.size(); right++){
        if(nums[right] == 0){
            zeroCount++;
        }
        while(zeroCount > k){
            if(nums[left] == 0){
                zeroCount--;
            }
            left++;
        }
        maxLength = max(maxLength, right - left + 1);
    }
    cout << "The maximum number of consecutive 1's is:\n";
    cout << maxLength << endl;
    // more optimal approach is not possible as we need to keep track of number of zeros in the current window
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // we will not change the window size as we need to find the maximum length of subarray with at most k zeros
    // approach is similar to longest subarray with sum at most k where we consider 0 as 1 and 1 as 0
    // we will maintain a window using two pointers and expand the window by moving right pointer
    // and whenever the number of zeros in the window exceeds k we will contract the window by moving left pointer
    // and update the maximum length of the window whenever we have a valid window
    int ans = 0;
    int l = 0;
    int r = 0;
    int n = nums.size();
    int zeros = 0;
    while(r < n){
        if(nums[r] == 0) zeros++;
        if(zeros > k){
            if(nums[l] == 0) zeros--;
            l++;
        }
        if(zeros <= k){
            ans = max(ans, r - l + 1);
        }
        r++;
    }
    cout << "The maximum number of consecutive 1's is:\n";
    cout << ans << endl;
    return 0;
}
