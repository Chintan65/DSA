#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
int arr2[(int)1e8]; // global array of size 10^7 or 1 10^8 is possible
// int arr3[(int)1e9]; // this will give error because size exceed the memory limit of global variable
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // hashing - means mapping large data to small data doing precompuqutationi
    // hash function - function which does the mapping
    // hash table - data structure which stores the hashed values
    // hash array - array which stores the hashed values 
    // array have O(1) access time but large memory
    // but array is not suitable for large data because of memory constraints
    // we can not creat array of size more then 10^6 in local variable
    // but in global variable we can create array of size 10^7
    // int arr[(int)1e7]; // this give segmentation fault in local variable

    cout << int('a') << " " << int('z') << endl; // 65 to 90
    cout << int('A') << " " << int('Z') << endl; // 97 to 122
    arr2['a'] = 1; // as 'a' converted to int is 97 so arr2[97] = 1
    cout << arr2[97] << endl;
    // for greter size > 10^6 of data we will use map
    // map have O(log n) access time for all best worst and avg but less memory java use treemap for map
    // unordered_map have O(1) avg access time but O(n) worst case time java use hashmap for unordered_map
    // unordered_map take O(n) time in worst case because of lot of collision
    // collision - when two different keys give same hash value
    // internally unordered_map use chaining to resolve collision
    // chaining - storing multiple values at same hash index using linked list
    // stl use dynamic resizing to avoid collision and internally increase the size of hash table when load factor exceed certain limit
    // stl implemented division method for hashing
    // division method - mod value very larg prime number to avoid collision - truncation method - convert into smaller size by removing some digits
    // for rxample mod = 5
    // arr = 10 2 3 5 6 7 8 5 
    // internally 
    // 0 - 10 5 5 // but it will not store like this it will use chaining and sort the values in linked list
    // 1 - 6
    // 2 - 2 7
    // 3 - 3 8
    // this will take time then it would be O(n) in worst case when all values give same mod value


    // collution happen when both value % mod give same value 



    return 0;
}
