#include <bits/stdc++.h>
using namespace std;
int main(){
	// this is tower of henoi problem where there is 3 tower A,B,C
	// we need to shift n disk from tower A to tower C  but there is condition
	// one disk at a time
	// no bigger disk on smaller disk 
	// only movement of top disk from tower
	// output number of steps and then all steps
	int n; cin >> n; 
	if(n==1) {
		cout << 1 << endl;
		cout << 1 << " " << 3 << endl;
		return 0;
	}
	// we will move n-1 disk from A to B using c as middle/auxiliary
	// nth disk from A to C
	// n-1 disk from B to C using A as middle/auxiliary
	// number of minimum step 2^n - 1
	cout << pow(2,n) - 1 << endl;


	
