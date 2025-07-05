#include <bits/stdc++.h>
using namespace std; // we use this to avoid writing std:: before every standard library function or object 
#define ll long long
#define ld long double // this is a type alias for long double, which is a floating-point type with more precision than double
// alias is a way to create a new name for an existing type, making the code more readable and easier to maintain

    int countDigit(int n) {
        int count = log10(n) + 1;
        return count;
    }

// proper divisor did not include number itself
int main(){ // main function is the entry point of the program
    // This line is used to speed up input and output operations in C++
    ios_base::sync_with_stdio(0); // ios_base::sync_with_stdio(0) disables the synchronization between C and C++
    cin.tie(0);     // cin.tie(0) unties cin from cout, allowing faster input operations
    cout.tie(0);     // cout.tie(0) unties cout from cin, allowing faster output operations
    // Runtime error : will occur when the program tries to access memory that it is not allowed to access.
    // Example: Dereferencing a null pointer, accessing an out-of-bounds array index,
    // or using an uninitialized variable.
    int x[5];
    cout << x[5] << endl; // This will cause a runtime error (out-of-bounds access)
    return 0;
}
