#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Example usage of bitwise operators
    int a = 5;      // Binary: 0101
    int b = 3;      // Binary: 0011
    cout << "a = " << a << ", b = " << b << "\n";
    cout << "a & b = " << (a & b) << "\n";  //  AND: 0001 -> 1
    cout << "a | b = " << (a | b) << "\n";  //  OR: 0111 -> 7
    cout << "a ^ b = " << (a ^ b) << "\n";  // XOR: 0110 -> 6
    // complement or NOT operator - inverts all bits
    // For positive numbers, ~n = -(n+1)
    // Example: a = 5 (0101) -> ~a = 1010 (which is -6 in decimal)
    // for negative numbers, ~n = -(n+1)
    // Example: a = -5 (in 32-bit: 11111111 11111111 11111111 11111011) -> ~a = 00000000 00000000 00000000 00000100 (which is 4 in decimal)
    cout << "~a = " << (~a) << "\n";        // NOT: 1010 -> -6
    // left shift make the number double for each shift
    cout << "a << 1 = " << (a << 1) << "\n"; // Left shift: 1010 -> 10
    // right shift make the number half for each shift
    cout << "a >> 1 = " << (a >> 1) << "\n"; // Right shift: 0010 -> 2
    return 0;
}
