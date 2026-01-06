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
Node* Reverse(Node* head){
    if(head == nullptr or head -> next == nullptr) return head;
    Node* prev = head;
    Node* curr = head -> next;
    prev -> next = nullptr;
    Node* temp;
    while(curr != nullptr){
        temp = curr;
        curr = curr -> next;
        temp -> next = prev;
        prev = temp;
    }
    return prev;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> nums = {2,0,2,1,1,0};
    int n = nums.size();
    Node* head = new Node(nums[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp -> next = new Node(nums[i]);
        temp = temp -> next;
    }
    cout << "Original Linked List: ";
    PrintLinkedList(head);
    head = Reverse(head);
    cout << "Reversed Linked List: ";
    PrintLinkedList(head);

    return 0;
}
