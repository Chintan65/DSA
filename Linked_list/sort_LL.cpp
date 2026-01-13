#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};

class Solution {
private:
    ListNode* Mid(ListNode* x){
        if(x == nullptr or x -> next == nullptr) return x;
        ListNode* slow = x;
        ListNode* fast = x -> next; // most importent as we want to break at mid - 1 for even length ll
        // else we will have cycle
        while(fast!= nullptr and fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
        
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(-1); // Using stack memory for dummy node to avoid memory leak
        ListNode* temp = &dummy;
        while(left != nullptr and right != nullptr){
            if(left -> val < right -> val){
                temp -> next = left;
                left = left -> next;
            }
            else {
                temp -> next = right;
                right = right -> next;
            }
            temp = temp -> next;
        }
        if(left != nullptr) temp -> next = left;
        if(right != nullptr) temp -> next = right;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr or head -> next == nullptr) return head;
        ListNode* mid = Mid(head);
        //cout << "mid - "  << mid -> val << endl;
        ListNode* temp = mid -> next;
        mid -> next = nullptr;
        head = sortList(head);
        temp = sortList(temp);
        return merge(head,temp);
        
    }
};
void printLinkedList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Linked List: 3 2 5 4 1
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(1);
    cout << "Original Linked List: ";
    printLinkedList(head);
    Solution solution;
    head = solution.sortList(head);
    cout << "Sorted Linked List: ";
    printLinkedList(head);
    return 0;
}
                