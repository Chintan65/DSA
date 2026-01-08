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
    bool hasCycle(ListNode *head) {
        // Detect cycle in linked list
        // method 1: using hash set to store visited nodes
        // traverse the list and for each node, check if it is in hash set
        // if yes, cycle detected
        // if no, add it to hash set and continue
        // time complexity O(n), space complexity O(n)

        // method 2: optimal approach
        // using Floyd's Tortoise and Hare Algorithm
        // maintain two pointers, slow and fast
        // slow moves one step at a time
        // fast moves two steps at a time
        // if there is a cycle, they will meet at some point
        // if there is no cycle, fast will reach null
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
        // overall slow is going 1 step away from head to cycle start
        // while fast is going 2 steps away from head to cycle start
        // hence they will meet if there is a cycle
        

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr and fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true; // cycle detected
            }
        }
        return false; // no cycle


    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ListNode* head = new ListNode(3);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(0);
    head -> next -> next -> next = new ListNode(-4);
    head -> next -> next -> next -> next = head -> next; // creating a loop here
    Solution sol;
    bool ans = sol.hasCycle(head);
    if(ans){
        cout << "Linked List has a cycle" << endl;
    } else {
        cout << "Linked List has no cycle" << endl;
    }
    
    return 0;
}
