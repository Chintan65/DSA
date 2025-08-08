#include <bits/stdc++.h>
using namespace std;
int main(){
    // boyer - moore's voting algorithm 
    // It is used to find the majority element in an array
    // A majority element is an element that appears more than n/2 times in the array
    // Time complexity - O(n)
    // Space complexity - O(1)
    // main logic - if there is majority element it can not be cancelled by any other element
    // It works by maintaining a count of the current candidate element and incrementing or decrementing
    // the count based on whether the current element matches the candidate or not
    // If the count becomes zero, the current element becomes the new candidate
    // After iterating through the array, we will find the candidate element
    // if there is a majority element, it will be the candidate
    // Otherwise, there is no majority element in the array
    vector<int> v = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int n = v.size();
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
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
    cout << "Candidate element : " << candidate << endl;
//--------------------------------------------------------------------------------------------------------------------------
    // new majority condition = n/3 and there can be more then one majority element
    v = {1,2,3,2,1,1,2,2,1};
    n = v.size();
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    // for n/3 condition we need to find two candidates
    // better then hash as it use O(1) space
    // we can use the same logic as above but we need to maintain two candidates and their counts
    int count1 = 0, count2 = 0;
    int candidate1 = INT_MIN, candidate2 = INT_MIN; // initialize candidates to invalid values
    for(int i=0;i<n;i++){
        if(count1 == 0 and v[i] != candidate2){
            candidate1 = v[i];
            count1 = 1;
        }
        else if(count2 == 0 and v[i] != candidate1){
            candidate2 = v[i];
            count2 = 1;
        }
        else if(v[i] == candidate1) count1++;
        else if(v[i] == candidate2) count2++;
        else {
            count1--;
            count2--;
        }
    }
    // but here we need to check if the candidates are actually majority elements
    count1 = 0;
    count2 = 0;
    for(int i=0;i<n;i++){
        if(v[i] == candidate1) count1++;
        else if(v[i] == candidate2) count2++;
    }
    cout << "candidate element :";
    if(count1 > n/3) cout <<  " " << candidate1;
    if(count2 > n/3) cout << " " << candidate2;
    cout << endl;



}