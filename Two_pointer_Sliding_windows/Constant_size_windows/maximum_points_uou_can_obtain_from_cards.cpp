#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class Solution{
  public:
    int maxScore(vector<int>& cardScore , int k){
      int suml = 0;
      int sumr = 0;
      for(int i=cardScore.size()-1;i>=cardScore.size()-k;i--) sumr+=cardScore[i];
      int ans = sumr;
      for(int l=0;l<k;l++){
        suml += cardScore[l];
        sumr -= cardScore[cardScore.size() - k + l];
        ans = max(ans,suml+sumr);
      }
      return ans;

    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // problem: Maximum Points You Can Obtain from Cards
    // you have n cards arranged in a row. Each card has an associated number of points given in the integer array cardPoints.
    // In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
    // Your score is the sum of the points of the cards you have taken.
    // Given the integer array cardPoints and the integer k, return the maximum score you can obtain.
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution sol;
    int result = sol.maxScore(nums, 3);
    cout << "The maximum score is:\n";
    cout << result << endl;

    return 0;
    return 0;
}
