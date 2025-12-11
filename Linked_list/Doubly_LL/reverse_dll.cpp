#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node* back;
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
void Print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
Node* Reverse(Node* head){
    if(head == nullptr or head -> next == nullptr) return head;
    Node* curr = head;
    Node* prev = nullptr;
    while(curr != nullptr){
        prev = curr -> back;
        curr -> back = curr -> next;
        curr -> next = prev;
        curr = curr -> back;
    }
    return prev -> back;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v = {4,3,3,3,3,3,4,2,3,4,0,2,1,5,6,7,0,8};
    int n = v.size();
    Node* head = new Node(v[0]);
    Node* temp = head;
    for(int i=1;i<n;i++) {
        Node* NN = new Node(v[i]);
        temp -> next = NN;
        NN -> back = temp;
        temp = NN;
    }
    // Reversing the doubly linked list
    Print(head);
    head = Reverse(head);
    Print(head);
    return 0;
}