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
    ListNode *findStartingPoint(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                // cycle detected
                // now find the starting point of the cycle
                fast = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // detection of starting node of loop in linked list
    // similar to loop detection using Floyd's Tortoise and Hare Algorithm
    // first detect if there is a loop using slow and fast pointers
    // if there is a loop, keep the slow pointer at the meeting point
    // move the fast pointer to the head of the linked list
    // now move both pointers one step at a time
    // the point at which they meet is the starting point of the loop   
    // time complexity O(n), space complexity O(1)
    // why it works?
    // let’s say the distance from head to the start of the cycle is d
    // and the length of the cycle is c
    // when slow and fast meet, let’s say slow has traveled s steps
    // then fast has traveled 2s steps
    // the extra distance traveled by fast is s
    // this extra distance must be a multiple of the cycle length c
    // hence, s = d + k*c for some integer k
    // thus, when they meet, slow has traveled d + k*c steps
    // which means it has gone d steps to reach the cycle start
    // and then k full cycles
    // so they will definitely meet within the cycle
    // now, when we move one pointer to head and keep the other at meeting point
    // and move both one step at a time
    // the pointer from head will take d steps to reach cycle start
    // the pointer from meeting point has already traveled d + k*c steps
    // so it needs to travel c - (d % c) steps to reach cycle start
    // since d % c + (c - (d % c)) = c
    // both pointers will meet at the starting point of the cycle

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = new ListNode(2); 
    head->next->next->next->next = head->next; // create a loop for testing
    Solution sol;
    ListNode* startingNode = sol.findStartingPoint(head);
    if(startingNode != nullptr){
        cout << "Starting node of loop is: " << startingNode->val << "\n";
    } else {
        cout << "No loop detected in the linked list.\n";
    }
    
    return 0;
}
