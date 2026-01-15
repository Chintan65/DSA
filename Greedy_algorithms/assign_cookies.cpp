#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class Solution{    
    public:
    int findMaximumCookieStudents(vector<int>& Student, vector<int>& Cookie){
        sort(Student.begin(),Student.end());
        sort(Cookie.begin(),Cookie.end());
        int i = 0;
        int j = 0;
        while(i < Student.size() and j < Cookie.size()){
            if(Student[i] <= Cookie[j]) i++,j++;
            else j++;
        }
        return i;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Greedy Algorithm is basically meeting the local optimum at each step with the hope of finding a global optimum.
    // Problem: Assign Cookies
    // You are given two arrays: one representing the greed factor of each child and the other representing the size of each cookie.
    // Your goal is to maximize the number of content children by assigning cookies to them.
    vector<int> Student = {1, 2};
    vector<int> Cookie = {1, 2, 3};
    Solution s;
    cout << s.findMaximumCookieStudents(Student, Cookie) << "\n";
    return 0;
}
