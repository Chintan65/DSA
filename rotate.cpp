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
    cout << s << endl; // Output: "intanch
    k = 25; // Example for rotating by more than the length of the string
    k = k % n; // Normalize k to prevent unnecessary full rotations
    rotate(s.begin(), s.begin() + k, s.end()); // Rotate the string by k positions left side
    cout << "After rotating by " << k << " positions: " << s << endl; 
    cout << "Rotating the string to the right by k position " << endl;
    rotate(s.begin(), s.end() - k, s.end()); // Rotate the string to the right by k positions
    cout << s << endl;    


    // other method to rotate 

    vector<int> v = {1,2,3,4,5,6};
    cout << "Original vector: ";
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;
    int d = 4;
    reverse(v.begin(),v.begin() + d); // Reverse the first d elements
    reverse(v.begin() + d, v.end()); // Reverse the remaining elements
    reverse(v.begin(), v.end()); // Reverse the entire vector to complete the rotation
    cout << "After rotating the vector by " << d << " positions: ";
    for(int i=0;i<v.size();i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}