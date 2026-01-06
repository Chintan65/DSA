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
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> nums = {1,2,3,4,5,6,7};
    int n = nums.size();
    Node* head = new Node(nums[0]);
    Node* temp = head;
    for(int i=1;i<n;i++){
        temp -> next = new Node(nums[i]);
        temp = temp -> next;
    }
    cout << "Original Linked List: ";
    PrintLinkedList(head);
    // Tortoise and Hare Algorithm to find middle of linked list
    // work on basis of two pointer approach    
    // slow and fast pointer
    // slow moves one step at a time
    // fast moves two steps at a time
    // we can use this approach to detect cycle in linked list also
    // if fast and slow meet at same node then there is a cycle
    // if fast reaches null then there is no cycle
    // many variations of this approach
    // here we will find middle node
    // if even number of nodes then we will return second middle node
    // if odd number of nodes then we will return middle node
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr and fast -> next != nullptr){// fast and fast->next should not be null
        slow = slow -> next;
        fast = fast -> next -> next;    
    }
    cout << "Middle Node is: " << slow -> data << endl;
    return 0;
}