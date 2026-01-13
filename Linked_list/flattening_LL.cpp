#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2) {
        val = data1;
        next = next1;
        child = next1;
    }
};

    
class Solution {
private:
    ListNode* merge(ListNode* x,ListNode* y){
        ListNode* dummy  = new ListNode(-1);
        ListNode* tp = dummy;
        while(x != nullptr and y != nullptr){
            if(x -> val < y -> val) {
                tp -> child = x;
                x = x -> child;
            }
            else {
                tp -> child = y;
                y = y -> child;
            }
            tp = tp -> child;
        }
        if(x != nullptr) tp -> child = x;
        if(y != nullptr) tp -> child = y;
        return dummy -> child;
    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        if(head == nullptr or head -> next == nullptr) return head;
        ListNode* Rhead = flattenLinkedList(head -> next);
        ListNode* Fhead = merge(Rhead,head);
        return Fhead;



    }
};



// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {

ListNode* head = new ListNode(5);
head->child = new ListNode(14);

head->next = new ListNode(7); // Moved 7 here
head->next->child = new ListNode(10); // Moved 10 here

head->next->next = new ListNode(12);
head->next->next->child = new ListNode(13); // Sorted
head->next->next->child->child = new ListNode(20); // Sorted

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Solution sol;
    
    // Function call to flatten the linked list
    ListNode* flattened = sol.flattenLinkedList(head);
    
    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}