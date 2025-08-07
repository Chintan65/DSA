#include <bits/stdc++.h>
using namespace std; 
void helper(vector<int> &v, int i,int n, vector<vector<int>> &result) {
    if(i == n) {
        result.push_back(v);
        return;
    }
    for(int j = i; j < n; j++) {
        swap(v[i], v[j]); // swap current element with the element at index i
        helper(v, i + 1, n, result); // recursively call for the next index
        swap(v[i], v[j]); // backtrack to restore the original array
    }
    // this will generate all possible permutations of the array
    // by swapping each element with the current index and recursively calling the function  
}
vector<vector<int>> All_permutation(vector<int> v){
    vector<vector<int>> result;
    sort(v.begin(), v.end());
    int n = v.size();
    helper(v,0,n,result);
    return result;

}
int main(){
    // permutation of array
    vector<int> v = {1,2,3,4};
    cout << "using C++ - STL unbuild function" << endl;
    int n = v.size();
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;
    next_permutation(v.begin(),v.end());
    // next_permutation function generates the next lexicographical permutation of the given array
    // if the array is already in the last permutation, it will return the first permutation
    // also it returns false if there is no next permutation
    for(int i=0;i<n;i++) cout << v[i] << " ";
    cout << endl;

    // all permutation  of array using C++ STL
    cout << "using C++ - STL unbuild function to get all permutation" << endl;
    vector<vector<int>> all_permutation;
    sort(v.begin(), v.end());
    do{
        all_permutation.push_back(v);
    } while (next_permutation(v.begin(), v.end()));

    for(auto &it:all_permutation){
        for(auto &i:it) cout << i << " ";
        cout << endl;
    }


    // using bruit force to get all permutation
    vector<vector<int>> all_permutation_recursion = All_permutation(v);
    cout << "using C++ - recursion to get all permutation" << endl;
    for(auto &it:all_permutation_recursion){
        for(auto &i:it) cout << i << " ";
        cout << endl;   
    }

    // next_permutation - code 
    // need to find first dip from right side like which decrese 
    // from that point to right need to find next just bigger point 
    // swaping with that point and then reverse the right side
    // this will give the next permutation in lexicographical order

    vector<int> vv = {2,1,5,4,3,0,0};
    sort(vv.rbegin(), vv.rend()); 
    vector<int> vv_copy = vv;
    int nn = vv.size();
    int i_dip = nn - 2;
    for(;i_dip >= 0; i_dip--){
        if(vv[i_dip] < vv[i_dip + 1]) break; // find first dip from right side
    }
    int i_next = nn - 1;
    for(;i_next > i_dip;i_next--){
        if(vv[i_next] > vv[i_dip]) break; // find next just bigger point
    }
    cout << "i_dip: " << i_dip << " i_next: " << i_next << endl;
    if(i_dip>=0) swap(vv[i_dip], vv[i_next]); // swap the dip with next just bigger point
    reverse(vv.begin() + i_dip + 1, vv.end());
    // reverse the right side to get the next permutation in lexicographical order
    cout << "next permutation using code" << endl;
    for(int i=0;i<nn;i++) cout << vv[i] << " ";
    cout << endl;
    next_permutation(vv_copy.begin(), vv_copy.end());
    cout << "next permutation using STL" << endl;   
    for(int i=0;i<nn;i++) cout << vv_copy[i] << " ";
    cout << endl;
    // both should give same output






    
    

}