#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr or head-> next == nullptr) return head;
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            n++;
            temp = temp -> next;
        }
        k = k % n;
        if(k == 0) return head;
        temp = head;
        for(int i=1;i<n-k;i++){
            temp = temp -> next;
        }
        ListNode* ans = temp -> next;
        ListNode* last = ans;
        while( last -> next != nullptr) last = last -> next;
        last -> next = head;
        temp -> next = nullptr;
        return ans;

        
        
    }
};
// Utility function to print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << "->";
        head = head->next;
    }
    cout << endl;
}
// Utility function to insert node at the end of the list
void insertNode(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Rotation of linked list by k
     // Inserting nodes
     ListNode* head = new ListNode(1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    Solution solution;
    // Calling function for rotating right by k times
    ListNode* newHead = solution.rotateRight(head, k);

    cout << "After " << k << " iterations: ";
    // List after rotating nodes
    printList(newHead);
    
    
    return 0;
}