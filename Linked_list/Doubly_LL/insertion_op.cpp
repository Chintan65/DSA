#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};
void PrintLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }
    cout << "nullptr" << endl;
}
void PrintLinkedListReverse(Node* head){
    Node* temp = head;
    while(temp-> next != nullptr) temp = temp -> next;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> back;
    }
    cout << "nullptr" << endl;
}
Node* InsertionAtHead(Node* head,int x){
    Node* NN = new Node(x);
    NN -> next = head;
    head -> back = NN;
    return NN;
}
Node* InsertionAtTail(Node* head, int x){
    Node* temp = head;
    while(temp -> next != nullptr) temp = temp -> next;
    Node* NN = new Node(x);
    NN -> back = temp;
    temp -> next = NN;
    return head; 
}
Node* InsertionAtKthPlace(Node* head,int x,int k){
    Node* NN = new Node(x);
    if(head == nullptr) return NN;
    else if(k == 1){
        NN -> next = head;
        head -> back = NN;
        return NN;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp  = temp -> next;
    }
    temp -> back -> next = NN;
    NN -> next = temp;
    NN -> back = temp -> back;
    temp -> back = NN;
    return head;

}
Node* InsertionBeforeKthNode(Node* head, int x, int k){
    Node* NN = new Node(x);
    if(head == nullptr) return head;
    Node* temp = head;
    while(temp -> data != k and temp != nullptr) {
        temp = temp -> next;
    }
    if(temp == head){
        NN -> next = head;
        head -> back = NN;
        return NN;
    }
    if(temp == nullptr) return head;
    NN -> back = temp -> back;
    NN -> next = temp;
    temp -> back -> next = NN;
    temp -> back = NN;


    return head;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v = {5,2,3,55,7,2,34,51,23,56,7,90};
    int n = v.size();
    Node* head = new Node(5);
    Node* temp = head;
    for(int i=1;i<n;i++){
        Node* tp = new Node(v[i],nullptr,temp);
        temp->next = tp;
        temp = temp -> next;
    }
    cout << "dobly linked list" << endl;
    PrintLinkedList(head);
    cout << "dobly linked list in reverse" << endl;
    PrintLinkedListReverse(head);
    cout << "insertion at head" << endl;
    head = InsertionAtHead(head,57);
    PrintLinkedList(head);
    PrintLinkedListReverse(head);
    cout << "insertion at tail" << endl;
    head = InsertionAtTail(head,91);
    PrintLinkedList(head);
    PrintLinkedListReverse(head);
    cout << "insert at kth element" << endl;
    head = InsertionAtKthPlace(head,99,4);
    PrintLinkedList(head);
    PrintLinkedListReverse(head);
    cout << "insertion before k node" << endl;
    head = InsertionBeforeKthNode(head,100,34);
    PrintLinkedList(head);
    PrintLinkedListReverse(head);

    
    return 0;
}
