#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // single number problem - 1
    // Given an array of integers where every element appears twice except for one, find that single one.
    vector<int> nums = {4,1,2,1,2};
    int single_number = 0;
    for (int num : nums) {
        single_number ^= num; // XORing all numbers
    }
    cout << "The single number is: " << single_number << "\n";
    // single number problem - 2
    // Given an array of integers where every element appears three times except for one, find that single one.
    nums = {2,2,3,2};
    int result = 0;
    for(int i=0;i<32;i++){
        int sum = 0;
        for(int num : nums){
            if(num & (1 << i)) sum++;
        }
        if(sum%3) result |= (1 << i);
    }
    cout << "The single number (appearing once while others thrice) is: " << result << "\n";
    // other approach using bit manipulation
    nums = {0,1,0,1,0,1,99};
    int ones = 0, twos = 0;
    for(int num : nums){
        ones = (ones ^ num) & ~twos; // add num to ones if it's not in twos
        twos = (twos ^ num) & ~ones; // Add the number to Twos, if it is already in Ones
    }
    cout << "The single number (appearing once while others thrice) is: " << ones << "\n";
    // single number problem - 3
    // in array every element appears twice except for two elements which appear only once. Find the two elements that appear only once.
    nums = {1,2,1,3,2,5};
    int xor_all = 0; // will hold xor of the two unique numbers
    for(int num : nums){
        xor_all ^= num; // XORing all numbers gives xor of the two unique numbers
    }
    // as xor_all will give all bits different between the two unique numbers
    // we can use any set bit to divide the numbers into two groups
    // this technique is called "bitmasking" - means using bits to represent a set of items
    // xor usage as a way to isolate unique elements
    int rightmost_set_bit = xor_all & -xor_all; // isolate rightmost set bit or xor_all & (xor_all - 1) ^ xor_all
    int num1 = 0, num2 = 0;
    for(int &num : nums){
        if(num & rightmost_set_bit) num1 ^= num; // group 1
        else num2 ^= num; // group 2
    }
    cout << "The two single numbers are: " << num1 << " and " << num2 << "\n";
    return 0;
}
