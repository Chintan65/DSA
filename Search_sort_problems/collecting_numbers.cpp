#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
You are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible. What will be the total number of rounds?
Input
The first line has an integer n: the array size.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Output
Print one integer: the number of rounds.
Constraints

1 \le n \le 2 \cdot 10^5

Example
Input:
5
4 2 1 5 3

Output:
3
    */

    /*
    When you need to process elements in a specific order (like 1 → n) but they appear in random order,
    what matters is the relative index order between consecutive elements — not their values.
    */
    int n; cin >> n;
    vector<int> coin(n),position(n);
    for(int i=0;i<n;i++) {
        cin >> coin[i];
        position[coin[i] - 1] = i;
    }
    int rounds = 0;
    for(int i=1;i<n;i++){
        if(position[i] < position[i-1]) rounds++;
    }
    cout << rounds + 1 << endl;
    return 0;
}
