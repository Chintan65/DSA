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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // one way is to use hash set to store nodes of one list and 
        // then traverse other list to find first node in hash set

        // other way is finding lengths of both lists
        // then moving pointer of longer list by difference in lengths
        // then move both pointers one step at a time
        // first node where they meet is intersection point

        // optimal way is two pointer approach
        // maintain two pointers, one for each list
        // move both pointers one step at a time
        // when any pointer reaches end of its list, redirect it to head of other list
        // if there is intersection point, both pointers will meet there after at most two traversals
        // if no intersection, both will reach end (nullptr) at same time
        // time complexity O(m+n), space complexity O(1)

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        while(ptr1 != ptr2){
            if(ptr1 == nullptr){
                ptr1 = headB;
            } else {
                ptr1 = ptr1 -> next;
            }
            if(ptr2 == nullptr){
                ptr2 = headA;
            } else {
                ptr2 = ptr2 -> next;
            }
        }
        return ptr1; // can be intersection node or nullptr

    }
    void PrintLinkedList(ListNode* head){
        ListNode* temp = head;
        while(temp != nullptr){
            cout << temp -> val << " -> ";
            temp = temp -> next;
        }
        cout << "nullptr" << endl;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // 1. Create the common part: 8 -> 4 -> 5
    ListNode* common = new ListNode(8);
    common->next = new ListNode(4);
    common->next->next = new ListNode(5);
    // 2. Create List 1: 4 -> 1 -> (common)
    ListNode* head1 = new ListNode(4);
    head1->next = new ListNode(1);
    head1->next->next = common;
    // 3. Create List 2: 5 -> 0 -> 1 -> (common)
    ListNode* head2 = new ListNode(5);
    head2->next = new ListNode(0);
    head2->next->next = new ListNode(1);
    head2->next->next->next = common; // Link to the same memory address 
    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(head1, head2);
    cout << "Linked List 1: ";
    sol.PrintLinkedList(head1);
    cout << "Linked List 2: ";
    sol.PrintLinkedList(head2);
    if(intersection != nullptr){
        cout << "Intersection at node with value: " << intersection -> val << endl;
    } else {
        cout << "No intersection point." << endl;
    }
    
    return 0;
}
