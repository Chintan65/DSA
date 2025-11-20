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
Node* DeleteAtHead(Node* head){
    if(head == nullptr) return nullptr;
    if(head -> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    head = head -> next;
    head -> back = nullptr;
    temp -> next = nullptr; // this not nessesory as we are going to delet that noe anywhay 
    //but may help in debugging and or some other node who targeted that temp
    delete temp;
    return head;
}
Node* DeleteAtTail(Node* head){
    if(head == nullptr) return nullptr;
    if(head-> next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr) temp = temp -> next;
    temp->back->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}
Node* DeletKthNode(Node* head, int k){
    if(head == nullptr) return nullptr;
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp -> next;
    }
    if(temp -> back == nullptr and temp->next == nullptr){
        delete temp;
        return nullptr;
    }
    else if(temp -> back == nullptr){
        head = head -> next;
        head -> back = nullptr;
        temp -> next = nullptr;
        delete temp;
        return head;
    }
    else if(temp -> next == nullptr){
        temp -> back -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
        return head;
    }
    else {
        temp -> back -> next = temp -> next;
        temp -> next -> back = temp -> back;
        temp -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
        return head;
    }
}
Node* DeletKElement(Node* head, int k){
    Node* temp = head;
    while(temp -> data != k) temp = temp -> next;
    if(temp -> back == nullptr and temp->next == nullptr){
        delete temp;
        return nullptr;
    }
    else if(temp -> back == nullptr){
        head = head -> next;
        head -> back = nullptr;
        temp -> next = nullptr;
        delete temp;
        return head;
    }
    else if(temp -> next == nullptr){
        temp -> back -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
        return head;
    }
    else {
        temp -> back -> next = temp -> next;
        temp -> next -> back = temp -> back;
        temp -> next = nullptr;
        temp -> back = nullptr;
        delete temp;
        return head;
    }
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
    cout << "deletation of head" << endl;
    head = DeleteAtHead(head);
    PrintLinkedList(head);
    cout << "deletation of tail" << endl;
    head = DeleteAtTail(head);
    PrintLinkedList(head);
    cout << "deletation of Kth Node" << endl;
    head = DeletKthNode(head,4);
    PrintLinkedList(head);
    cout << "deletation of k element" << endl;
    head = DeletKElement(head,23);
    PrintLinkedList(head);
    return 0;
}
