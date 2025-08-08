#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void merge(vector<int>& nums,int l, int m, int r, int& reverse_pair){
        vector<int> tp;
        int i = l, j = m + 1;
        while(i<=m and j <=r){
            if(nums[i] <= nums[j]){
                tp.push_back(nums[i]);
                i++;
            }
            else {
                if(nums[i] > 2*nums[j]) reverse_pair += (m - i + 1);
                tp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= m){
            tp.push_back(nums[i]);
            i++;
        }
        while(j <= r){
            tp.push_back(nums[j]);
            j++;
        }
        for(int k = l; k<=r; k++) nums[k] = tp[k - l];

    }
    void ms(vector<int>& nums, int l, int r, int& reverse_pair){
        int m = l + (r - l) / 2;
        if(l>=r) return; // base case
        ms(nums,l,m,reverse_pair);
        ms(nums,m+1,r,reverse_pair);
        merge(nums,l,m,r,reverse_pair);
    }
    int reversePairs(vector<int>& nums){
        int n = nums.size();
        int reverse_pair = 0;
        ms(nums, 0, n-1, reverse_pair);
        return reverse_pair;

    }
};
int main(){

    //Given an integer array nums, return the number of reverse pairs in the array.
    //A reverse pair is a pair (i, j) where:
    //0 <= i < j < nums.length and
    //nums[i] > 2 * nums[j].

    vector<int> nums = {6, 4, 1, 2, 7};
    Solution s;
    int ans = s.reversePairs(nums);
    cout << "Number of reverse pairs: " << ans << endl;
    return 0;
}