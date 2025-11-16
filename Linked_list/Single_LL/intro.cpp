#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr; 
        }
};
void PrintLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "nullptr" << endl; 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[5] = {10,20,30,40,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = new Node(arr[0]); // first node
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    // print linked list
    PrintLinkedList(head);



    return 0;
}
