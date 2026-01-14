#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a = 5;      // Binary: 0101
    cout << "Original a = " << a << "\n";
    // Trick 1: Check if a number is even or odd using bitwise AND
    if (a & 1) cout << a << " is odd\n";
    else cout << a << " is even\n";
    // trick 2: xor with itself gives 0
    int b = a ^ a;
    cout << "a ^ a = " << b << "\n"; // should print 0
    // trick 3: swap two numbers without a temporary variable
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << "\n";
    x = x ^ y; // step 1
    y = x ^ y; // here y becomes original x a x = x ^ y and y = (x ^ y) ^ y = x
    x = x ^ y; // here x becomes original y a x = (x ^ y) ^ x = y
    cout << "After swap: x = " << x << ", y = " << y << "\n";
    // trick 4: check if ith bit is set or not
    // using left shift
    int i = 3;
    cout << "Checking if " << i << "th bit of a is set or not:\n";
    if (a & (1 << i)) cout << i << "th bit is set\n";
    else cout << i << "th bit is not set\n";
    // using right shift
    if ((a >> i) & 1) cout << i << "th bit is set\n";
    else cout << i << "th bit is not set\n";
    // trick 5: set ith bit
    cout << "Setting " << i << "th bit of a:\n";
    int set_bit = a | (1 << i);
    cout << "After setting " << i << "th bit, a = " << set_bit << "\n";
    // trick 6: clear ith bit
    cout << "Clearing " << i << "th bit of a:\n";
    int clear_bit = a & (~(1 << i));
    cout << "After clearing " << i << "th bit, a = " << clear_bit << "\n";
    // trick 7: toggle ith bit
    cout << "Toggling " << i << "th bit of a:\n";
    int toggle_bit = a ^ (1 << i);
    cout << "After toggling " << i << "th bit, a = " << toggle_bit << "\n";
    // trick 8: count number of set bits (Hamming Weight)
    // Haming weight is the number of symbols that are different from the zero-symbol of the alphabet used.
    // Time complexity O(number of bits)
    int count = 0;
    int temp = a;
    while (temp) {
        count += (temp & 1);        
        temp >>= 1;
    }
    cout << "Number of set bits in " << a << " = " << count << "\n";
    // Alternatively, using __builtin_popcount in GCC/Clang
    int popcount = __builtin_popcount(a);
    cout << "Number of set bits (using __builtin_popcount) in " << a << " = " << popcount << "\n";
    // also for long long use __builtin_popcountll
    long long popcountll = __builtin_popcountll((long long)a);
    cout << "Number of set bits (using __builtin_popcountll) in " << a << " = " << popcountll << "\n";
    // another method is Brian Kernighan’s Algorithm
    count = 0;
    temp = a;
    while (temp) {
        temp = temp & (temp - 1); // removes the last set bit
        count++;
    }
    cout << "Number of set bits (using Brian Kernighan’s Algorithm) in " << a << " = " << count << "\n";
    // trick 9: Last set bit
    int last_set_bit = a & (-a);
    cout << "Last set bit of " << a << " = " << last_set_bit << "\n";
    // trick 10: Turn off the last set bit
    int turn_off_last_set_bit = a & (a - 1); // Time complexity O(1)
    // removes the last set bit from a
    // reason this works is a-1 will have all bits
    // same as a from left side to last set bit
    // and last set bit will become 0 and all
    // bits to right of last set bit will be inverted   
    // so when ANDed with a, last set bit is turned off
    // example: a = 12 (1100)
    // a-1 = 11 (1011)
    // a & (a-1) = 1100 & 1011 = 1000 (last set bit turned off) 
    cout << "After turning off last set bit of " << a << " = " << turn_off_last_set_bit << "\n";
    // trick 11: Check if a number is power of two
    if (a > 0 && (a & (a - 1)) == 0) cout << a << " is power of two\n"; // as last set bit turned off should give 0
    // for zero or negative numbers, it is not power of two 
    // Time complexity of above operation is O(1) 
    else cout << a << " is not power of two\n";
    return 0;
}
