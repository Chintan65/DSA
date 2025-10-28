#include <bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(2);
    ms.insert(3);
    ms.insert(4);
    ms.insert(5);
    ms.insert(6);
    auto it = ms.lower_bound(3);
    
    int dt = distance(ms.begin(), it);
    int dt2 = distance(it,ms.end());
    cout << dt << " " << dt2 << endl;
    return 0;

}