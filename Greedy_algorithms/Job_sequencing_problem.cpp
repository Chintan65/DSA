#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class Solution{  
  private:
    bool static cmp(vector<int> &a, vector<int> &b){
      return b[2] < a[2];
    }
  public:  
    vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
      sort(Jobs.begin(),Jobs.end(),cmp);
      int cnt = 0;
      int profit = 0;
      int md = -1;
      int n = Jobs.size();
      for(int i=0;i<n;i++) md = max(md,Jobs[i][1]);
      vector<int> vis(md+1,-1);
      for(int i=0;i<n;i++){
        for(int j = Jobs[i][1]; j>=1; j--){
          if(vis[j] == -1) {
            vis[j] = 1, profit += Jobs[i][2], cnt++;
            break;
          }
        }
      }
      return {cnt,profit};
    } 
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Job sequencing problem with deadlines and profits
    // Given a set of jobs where each job has a deadline and a profit associated with it
    // the task is to find the maximum profit and the number of jobs done within their deadlines.
    // Each job takes a single unit of time and only one job can be scheduled at a time.
    vector<vector<int>> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    Solution solution;
    vector<int> result = solution.JobScheduling(jobs);
    cout << "Number of Jobs: " << result[1] << endl;
    cout << "Maximum Profit: " << result[0] << endl;
    return 0;
}
