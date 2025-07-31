#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {-1, 2, 3, -1, 2, -6, 5};
    int n = v.size();
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    // kadane's algoritham 
    // Time complexity - O(n)
    // Space complexity - O(1)
    // This algorithm is used to find the maximum sum of a contiguous subarray in an array
    // It works by maintaining a running sum and resetting it to zero whenever it becomes negative
    // The maximum sum is updated whenever the running sum exceeds the current maximum
    // It is efficient and works well for large arrays, making it a popular choice for solving
    // maximum subarray sum problems.
    // It is a fundamental algorithm in computer science and is often used in various applications
    // such as financial analysis, data processing, and optimization problems.

    
    int maxi = INT_MIN;
    int sum = 0;
    // i will carry sum if it has some value means > 0 otherwise no sence to carry
    for(int i=0;i<n;i++){
        sum += v[i];
        if(sum > maxi) maxi = sum; // update max sum
        if(sum < 0) sum = 0; // reset sum if it is negative
    }
    cout << "Maximum subarray sum is - " << maxi << endl;

    // kadanes in financial analysis
    // It can be used to find the maximum profit from a series of stock prices by treating
    // the stock prices as an array and applying the algorithm to find the maximum profit
    // that can be obtained by buying and selling stocks at different prices.
    // It can also be used to find the maximum profit from a series of transactions in a
    // financial portfolio by treating the transactions as an array and applying the algorithm
    // to find the maximum profit that can be obtained by buying and selling assets at different prices 
  
}