#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class solution {
public:	
    vector<vector<int> > powerSet(vector<int>& nums) {
        int n = nums.size();
        int x = (1 << n);
        vector<vector<int>> ans;
        for(int i=0;i<x;i++){
            vector<int> subset;
            for(int j=0;j<n;j++){
                if(i & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;

    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> nums = {1, 2, 3};
    solution sol;
    vector<vector<int>> result = sol.powerSet(nums);
    for (const auto& subset : result) { 
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
