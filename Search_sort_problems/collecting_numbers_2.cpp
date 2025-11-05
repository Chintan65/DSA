#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
ou are given an array that contains each number between 1 \dots n exactly once. Your task is to collect the numbers from 1 to n in increasing order.
On each round, you go through the array from left to right and collect as many numbers as possible.
Given m operations that swap two numbers in the array, your task is to report the number of rounds after each operation.
Input
The first line has two integers n and m: the array size and the number of operations.
The next line has n integers x_1,x_2,\dots,x_n: the numbers in the array.
Finally, there are m lines that describe the operations. Each line has two integers a and b: the numbers at positions a and b are swapped.
Output
Print m integers: the number of rounds after each swap.
Constraints

1 \le n, m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
4 2 1 5 3
2 3
1 5
2 3

Output:
2
3
4
    */

    /*
    When you need to process elements in a specific order (like 1 → n) but they appear in random order,
    what matters is the relative index order between consecutive elements — not their values.
    */
    int n,m; cin >> n >> m;
    int rounds = 0;
    vector<int> v(n+1),position(n+1);
    for(int i=1;i<=n;i++){
        cin >> v[i];
        position[v[i]] = i;
    }
    for(int i=2;i<=n;i++){
        if(position[i] < position[i-1]) rounds++;
    }
    rounds += 1;
    cout << rounds << endl;
    while(m--){
        int a,b; cin >> a >> b;
        if(a == b){
            cout << rounds << endl;
            continue;
        }
        if(a == b+1 or b == a+1){
            if(v[a] > v[b]) rounds--; 
            else rounds++;
            swap(v[a],v[b]);
            position[v[a]] = a;
            position[v[b]] = b;
            cout << rounds << endl;
            continue;
        }
        int val_a = v[a];
        int val_b = v[b];
        int new_a = b;
        int new_b = a;
        int cnt = 0;
        if(val_a - 1 >= 1){
            if(a < position[val_a - 1]) cnt--;
            if(b < position[val_a - 1]) cnt++;
        }
        if(val_a + 1 <= n){
            if(position[val_a + 1] < a) cnt--;
            if(position[val_a + 1] < b) cnt++;
        }
        if(val_b - 1 >= 1){
            if(b < position[val_b - 1]) cnt--;
            if(a < position[val_b - 1]) cnt++;
        }
        if(val_b + 1 <= n){
            if(position[val_b + 1] < b) cnt--;
            if(position[val_b + 1] < a) cnt++;
        }
        rounds += cnt;
        swap(v[a],v[b]);
        position[val_a] = new_a;
        position[val_b] = new_b;
        cout << rounds << endl;


    }
}
