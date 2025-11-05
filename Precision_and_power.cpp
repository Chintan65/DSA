
#include <bits/stdc++.h>
using namespace std;

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;

// Fast power function using binary exponentiation
cpp_int power(cpp_int n, int m) {
    cpp_int result = 1;
    while (m > 0) {
        if (m % 2 == 1) result *= n;
        n *= n;
        m /= 2;
    }
    return result;
}

int main() {
    // Exponentiation by squaring / binary exponentiation
    // n ^ m fastest exponentiation
    // time complexity - O(log m)
    // space complexity - O(1)
    int n = 5, m = 30;  // example numbers
    cpp_int res = power(n, m);
    cout << n << "^" << m << " = " << res << endl;
    return 0;
}
