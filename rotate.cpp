#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s = "chintan";
    // rotate the string to the left by 2 positions
    int k = 2;
    int n = s.length();
    // Using the STL rotate function
    rotate(s.begin(), s.begin()+2, s.end()); // this work as rotate(start, middle(this will be new first), end)
    cout << s << endl; // Output: "intanch"
    cout << "Rotating the string to the left by 1 position " << endl;
    for(int i=0;i<n;i++){
        rotate(s.begin(), s.begin()+1, s.end()); // this will rotate the string to the left by 1 position
        cout << s << endl; 
    }
    return 0;
}