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
    PrintLinkedList(head);
    PrintLinkedListReverse(head);

    
    return 0;
}
