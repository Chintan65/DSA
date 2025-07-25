#include <bits/stdc++.h>
using namespace std;
int fibo_constant_space(int n){
    if(n<=1) return 0;
    int first = 1, second = 1;
    int tp;
    for(int i=2;i<n;i++){
        tp = second;
        second = first+ second;
        first = tp;
    }
    return second;

}
int fibo(int n){
    if(n<=1) return 1;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}
int main(){
    // dynameic programing 
    // 3 type of problem when we use dynamic programing 
    // 1. count something - number of ways - rearenge the elements that satisfie some condition , etc 
    // 2. minimize or maximize certain value
    // 3. YES/NO question - example - sum of subset equal to certain value 
    // some time need to check if greedy is easier approch or not
    // two approch iteration and recursion 
    // hard problem - iteration may help to emplement complex logic
    //  easy to apply - recursion and also order of state does not matter - for example sometime in graph 
    // genrally use for better time complexity

    cout << fibo(8) << endl;
    cout << fibo_constant_space(8) << endl;
    
    
}