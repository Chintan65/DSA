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
void PrintLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << "nullptr" << endl;
}
Node* RemoveHead(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    head = head -> next;
    delete temp; // free memory also we can use free(temp) if we used malloc    
    // in java or python we don't need to free memory manually as they have garbage collection
    // in c++ smart pointers can also be used to manage memory automatically
    return head;
}
Node* RemoveTail(Node* head){
    if(head == nullptr) return nullptr;
    if(head -> next == nullptr){
        delete head;
        return nullptr;
    } 
    Node* temp = head;
    while(temp -> next -> next != nullptr){
        temp = temp -> next;
    }
    Node* toDelete = temp -> next;
    temp -> next = nullptr;
    delete toDelete;
    return head;
}
Node* RemoveKthElement(Node* head, int k){
    if(head == nullptr) return nullptr;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node * prev = nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) {
            prev -> next = prev -> next -> next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
Node* RemoveXElement(Node* head, int x){
    if(head == nullptr) return nullptr;
    if(head -> data == x){
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp->next != nullptr){
        if(temp->data == x){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v = {5,2,3,55,7,2,34,51,23,56,7,90};
    int n = v.size();
    Node* head = VectorToLinkedList(v);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "remove head node" << endl;
    head = RemoveHead(head);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "remove tail node" << endl;
    head = RemoveTail(head);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "delet kth element" << endl;
    head = RemoveKthElement(head,9);
    cout << "Linked List: ";
    PrintLinkedList(head);
    cout << "delet x element" << endl;
    head = RemoveXElement(head,34);
    cout << "Linked List: ";
    PrintLinkedList(head);
    return 0;
}