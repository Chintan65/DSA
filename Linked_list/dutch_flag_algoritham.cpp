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
Node* DNF(Node* head){
    if(head == nullptr or head -> next == nullptr) return head;
    Node* zeroD = new Node(-1);
    Node* zero = zeroD;
    Node* oneD = new Node(-1);
    Node* one = oneD;
    Node* twoD = new Node(-1);
    Node* two = twoD;
    while(head != nullptr){
        if(head -> data == 0){
            zero -> next = head;
            zero = zero -> next;
        }
        else if(head -> data == 1){
            one -> next = head;
            one = one -> next;
        }
        else {
            two -> next = head;
            two = two -> next;
        }
        head = head -> next;
    }
    two -> next = nullptr;
    one -> next = twoD -> next;
    zero -> next = oneD -> next;
    head = zeroD -> next;
    delete zeroD;
    delete oneD;
    delete twoD;
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
    cout << "After Dutch National Flag Sorting: ";
    head = DNF(head);
    PrintLinkedList(head);
}
