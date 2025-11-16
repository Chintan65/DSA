#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
    int add(int a, int b) { return a + b; }
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // pointer example
    int x = 5;
    int* y = &x;
    cout << x << endl;
    cout << y << endl; // address of x
    cout << &x << endl; // address of x
    cout << *y << endl; // usage of dereferencing operator
    // pointer means address of variable 
    int* xp = nullptr; // null pointer
    x = 20;
    cout << *y << endl; // y points to x so *y gives value of x
    *y = 30; // changing value at address y points so x changes
    cout << x << endl;
    // pointer arithmetic
    int arr[5] = {1,2,3,4,5};
    int* p = arr; // arr is address of first element arr[0]
    cout << p << endl; // address of first element
    cout << *p << endl; // 1
    p++; // moves to next integer (4 bytes ahead)
    cout << *p << endl; // 2
    cout << p[2] << endl; // 4 because p points to arr[1] and p[2] is arr[3] p[2] = *(p + 2)
    // pointer to pointer
    cout << "pointer to pointer example" << endl;
    x = 25;
    int* p1 = &x;
    int** p2 = &p1;
    cout << p2 << endl; // address of p1]
    cout << "address of p1: " << &p1 << endl;
    cout << "address of x: " << &x << endl;
    cout << *p2 << endl; // address of x
    cout << **p2 << endl; // 25 and this is pointing to value of x
    cout << *p1 << endl; // 25
    cout << x << endl; // 25
    const int xc = 10;
    const int* ptr = &xc;  // OK
//*ptr = 20;  // Error: can't modify


    void* vptr = &x;  // x is int
    int* iptr = static_cast<int*>(vptr);  // Cast back to dereference

    int (*funcPtr)(int, int) = add;  // Or &add
    std::cout << funcPtr(1, 2);  // Outputs 3

    int* ptrx = new int(10);  // Allocates and initializes
    delete ptrx;  // Deallocates
    ptrx = nullptr;  // Prevent dangling
    
    return 0;
}
