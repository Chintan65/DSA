#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int Binary_Search(vector<int> &nums, int L, int R, int target){
    if(L > R) return -1;
    int M = L + (R-L)/2;
    if(nums[M] > target) return Binary_Search(nums,L,M-1,target);
    else if(nums[M] < target) return Binary_Search(nums,M+1,R,target);
    else return M;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> nums = {1,3,4,6,7,12,15,34,56,78};
    int x = 7;
    cout << "element - " << x << " index is - " << Binary_Search(nums,0,nums.size(),x) << endl;
    x = 8;
    cout << "element - " << x << " index is - " << Binary_Search(nums,0,nums.size(),x) << endl;
    return 0;
}
