#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
class Node {
    public:
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }
};
void PrintLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "nullptr" << endl;
}
Node* VectorToLinkedList(vector<int> &v){
    if(v.empty()) return nullptr;
    Node* head = new Node(v[0]);
    Node* temp = head;
    for(int i=1;i<v.size();i++){
        temp -> next = new Node(v[i]);
        temp = temp -> next;
    }
    return head;
}
Node* InsertAtHead(Node* head, int x){
    Node* temp = new Node(x);
    temp -> next = head;
    return temp;
}
Node* InsertAtTail(Node* head, int x){
    Node* temp = new Node(200);
    if(head == nullptr) return temp;
    Node* tp = head;
    while(tp->next != nullptr) tp = tp -> next;
    tp->next = temp;
    return head;
}
Node* InsertAtkthPlace(Node* head,int x,int k){
    if(k == 1){
        Node* temp = new Node(x);
        temp->next = head;
        return temp;
    }
    Node* tp = head;
    int cnt = 1;
    while(tp->next != nullptr){
        cnt++;
        if(cnt == k){
            Node* temp = new Node(x);
            temp -> next = tp -> next;
            tp -> next = temp;
            return head;
        }
        tp = tp -> next;
    }
    Node* temp = new Node(x);
    tp -> next = temp;
    return head;

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v = {5,2,3,55,7,2,34,51,23,56,7,90};
    int n = v.size();
    Node* head = VectorToLinkedList(v);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "Inserting 100 at the beginning." << endl;
    head = InsertAtHead(head,100);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "Inserting 200 at the end." << endl;
    head = InsertAtTail(head,200);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "Inserting at kth element" << endl;
    head = InsertAtkthPlace(head,500,15);
    cout << "Linked List: ";
    PrintLinkedList(head);
    
    return 0;
}
