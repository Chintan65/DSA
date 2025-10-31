#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class Solution {
public:
    // here array is rotated and sorted and unique element are present
    // time complexity - O(log n)
    // space complexity - O(1)
    int search(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int M;
        while(L <= R){
            M = L + (R - L) / 2;
            if(nums[M] == target) return M;
            else if(nums[L] <= nums[M]){
                if(target >= nums[L] and target <= nums[M]) R = M - 1;
                else L = M + 1;
            }
            else{
                if(target <= nums[R] and target >= nums[M]) L = M + 1;
                else R = M - 1;
            }
        }
        return -1; 
    }
    // here array is rotated and sorted and duplicate element are present
    // time complexity - O(log n) in average case and O(n) in worst case
    // space complexity - O(1)
    int searchWithDuplicate(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int M;
        while(L <= R){
            M = L + (R - L) / 2;
            if(nums[M] == target) return M;
            if(nums[L] == nums[M] and nums[M] == nums[R]){
                L++;
                R--;
            }
            else if(nums[L] <= nums[M]){
                if(target >= nums[L] and target <= nums[M]) R = M - 1;
                else L = M + 1;
            }
            else{
                if(target <= nums[R] and target >= nums[M]) L = M + 1;
                else R = M - 1;
            }
        }
        return -1; 
    }

};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Solution x;
    vector<int> v = {4,5,6,7,0,1,2};
    int target = 5;
    cout << "element - " << target << " index is - " << x.search(v,target) << endl; 
    v = {4,5,6,7,0,1,2,4,4};
    target = 0;
    cout << "element - " << target << " index is - " << x.searchWithDuplicate(v,target) << endl;
    
    return 0;
}
