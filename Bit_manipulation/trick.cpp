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
    // trick 12: __builtin_parity
    // returns 1 if number of set bits is odd else returns 0
    int parity = __builtin_parity(a);
    cout << "Parity of " << a << " = " << parity << "\n";
    // for long long use __builtin_parityll
    int parityll = __builtin_parityll((long long)a); // Time complexity O(1)
    cout << "Parity of " << a << " (using __builtin_parityll) = " << parityll << "\n";
    // trick 13: __builtin_ctz  -> help in finding LSB (least significant bit)
    // for 0 input, the result is undefined
    // returns the number of trailing zeros in binary representation
    int ctz = __builtin_ctz(a); // Time complexity O(1)
    cout << "Number of trailing zeros in " << a << " = " << ctz << "\n";
    // for long long use __builtin_ctzll
    int ctzll = __builtin_ctzll((long long)a);
    cout << "Number of trailing zeros in " << a << " (using __builtin_ctzll) = " << ctzll << "\n";
    // trick 14: __builtin_clz -> help in finding MSB (most significant bit)
    // for 0 input, the result is undefined
    int clz = __builtin_clz(a); // Time complexity O(1)
    cout << "Number of leading zeros in " << a << " = " << clz << "\n";
    // for long long use __builtin_clzll
    int clzll = __builtin_clzll((long long)a);
    cout << "Number of leading zeros in " << a << " (using __builtin_clzll) = " << clzll << "\n";   
    // returns the number of leading zeros in binary representation
    // trick 15: number of flipped bits to convert a to b
    int a1 = 29; // Binary: 11101
    int b1 = 15; // Binary: 01111
    int flipped_bits = a1 ^ b1; // XOR will give bits which are different
    int num_flipped_bits = __builtin_popcount(flipped_bits); // count set bits
    cout << "Number of bits to be flipped to convert " << a1 << " to " << b1 << " = " << num_flipped_bits << "\n";
    return 0;
}
