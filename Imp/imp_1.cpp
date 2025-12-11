#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {4,3,3,3,3,3,4,2,3,4,0,2,1,5,6,7,0,8};
    multiset<int> st(v.begin(),v.end());
    int x = 5;
    auto it1 = st.upper_bound(x);
    auto it2 = upper_bound(v.begin(),v.end(),x);
    // it1 and it2 will point to same element
    // but the way to get there is different 
    // because one is using multiset and other is using vector
    // so the iterators are different type but point to same element
    // both will take different time complexities
    // multiset upper_bound -> O(log n)
    // vector upper_bound -> O(n)
    // other data structures also have their own complexities like set, map, unordered_set, unordered_map etc.
    

    // erase method in multiset or any other STL container 
    st.erase(st.find(3)); // erases only one occurrence of 3
    cout << "Multiset elements after erasing one occurrence of 3: ";
    for(auto val : st) cout << val << " ";
    cout << endl;   
    st.erase(3); // erases all occurrences of 3
    cout << "Multiset elements after erasing all occurrences of 3: ";
    for(auto val : st) cout << val << " ";
    cout << endl;
}