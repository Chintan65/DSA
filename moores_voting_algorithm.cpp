#include <bits/stdc++.h>
using namespace std;
int main(){
    // moore's voting algorithm 
    // It is used to find the majority element in an array
    // A majority element is an element that appears more than n/2 times in the array
    // Time complexity - O(n)
    // Space complexity - O(1)
    // It works by maintaining a count of the current candidate element and incrementing or decrementing
    // the count based on whether the current element matches the candidate or not
    // If the count becomes zero, the current element becomes the new candidate
    // After iterating through the array, we will find the candidate element
    // if there is a majority element, it will be the candidate
    // Otherwise, there is no majority element in the array
    vector<int> v = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int n = v.size();
    int count  = 0;
    int candidate = -1; // initialize candidate to -1 or any invalid value
    for(int i=0;i<n;i++){
        if(count ==0){
            candidate = v[i];
            count = 1; // reset count to 1 for the new candidate
        }
        else if(v[i] == candidate) count++; // increment count if current element is the candidate
        else count--; // decrement count if current element is not the candidate
    }
    cout << "Candidate element is - " << candidate << endl;
}