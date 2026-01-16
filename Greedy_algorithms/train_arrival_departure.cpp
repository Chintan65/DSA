#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Train Arrival and Departure Problem
    vector<int> arrivals = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departures = {910, 1200, 1120, 1130, 1900, 2000};
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    int n = arrivals.size();
    int platform_needed = 0, max_platforms = 0;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(arrivals[i] < departures[j]){
            platform_needed++;
            max_platforms = max(max_platforms, platform_needed);
            i++;
        }
        else{
            platform_needed--;
            j++;
        }
    }
    cout << "Minimum number of platforms required: " << max_platforms << "\n";
    return 0;
}
