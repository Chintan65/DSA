#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
vector<int> Bit_converter(int n){
    // Time Complexity : O(log n)
    // Space Complexity : O(log n)
    vector<int> res;
    while(n){
        res.push_back(n % 2);
        n = n / 2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int Decimal_converter(const vector<int>& bits){
    // Time Complexity : O(log n)
    // Space Complexity : O(1)
    int n = bits.size();
    int res = 0;
    for(int i = 0; i < n;i++){
        res = res + bits[n - i - 1] * (1 << i);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = 57;
    // convertion of n to its binary representation
    cout << "Binary representation of " << n << " is : ";
    vector<int> n_bit = Bit_converter(n);
    for(auto x : n_bit) cout << x;
    cout << endl;
    // convertion of binary representation to its decimal value
    cout << "Decimal value of binary representation is : ";
    int x = Decimal_converter(n_bit);
    cout << x << endl;
    // also c++ converter of decimal to binary and vice versa
    cout << "Using C++ built-in functions :" << endl;
    // Decimal to binary using bitset
    cout << "Binary representation of " << n << " is : ";
    bitset<32> b(n); // assuming 32 bits for representation
    cout << b << endl;
    string binary_str = b.to_string();
    cout << "String representation of binary is : " << binary_str << endl;
    // from string to bitset
    bitset<32> b_from_str(binary_str);
    cout << "Bitset from string is : " << b_from_str << endl;
    // Binary to decimal using bitset
    cout << "Decimal value of binary representation is : ";
    int decimal_value = (int)(b.to_ulong());
    cout << decimal_value << endl;  
    // 1s complement of n 
    cout << "1's complement of " << n << " is : ";
    int ones_complement = ~n;
    cout << ones_complement << endl;
    // 2s complement of n
    cout << "2's complement of " << n << " is : ";
    int twos_complement = ~n + 1;
    cout << twos_complement << endl;
    

    return 0;
}
