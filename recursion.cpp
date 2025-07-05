#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
void fun(){
    if(cnt == 4){
        return;
    }
    cout << "chintan" << endl;
    cnt++;
    fun();
}
int main(){
    fun();

    // stack overflow: occurs when the program uses more stack space than is available, typically due to excessive recursion or large local variables.
    // Example: A recursive function that does not have a base case or has a base case
    // that is never reached, leading to infinite recursion.
    // In this case, the function fun() will keep calling itself until the stack space is
    // exhausted, resulting in a stack overflow error.
    // To avoid this, ensure that your recursive functions have a proper base case that
    // terminates the recursion when a certain condition is met.
    // In this case, the base case is when cnt == 4, which stops the recursion. 
    // If you remove the base case, the function will keep calling itself indefinitely,
    // leading to a stack overflow error. or segmentation fault error.
}
