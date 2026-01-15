#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // shortest job first (SJF) is a scheduling algorithm that selects the process with the smallest execution time to execute next.
    vector<int> jobs = {6, 8, 7, 3, 4};
    sort(jobs.begin(), jobs.end());
    int total_waiting_time = 0;
    int n = jobs.size();
    int time_elapsed = 0;
    for(int i = 0; i < n; i++){
        total_waiting_time += time_elapsed;
        time_elapsed += jobs[i];
    }
    cout << total_waiting_time << "\n";
    cout << "Average waiting time: " << (double)total_waiting_time / n << "\n";
}
