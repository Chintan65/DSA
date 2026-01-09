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
    int findLengthOfLoop(ListNode *head) {
        // detection of loop in linked list using Floyd's Tortoise and Hare Algorithm
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr and fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                // clycle detected
                // now find the length of the loop
                int cnt = 1;
                while(fast->next != slow){
                    fast = fast -> next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0; // no loop
    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // length of loop in linked list
    // first detect if there is a loop using Floyd's Tortoise and Hare Algorithm
    // if there is a loop, keep one pointer at the meeting point
    // move the other pointer one step at a time
    // count the number of steps taken to meet the first pointer again
    // this count is the length of the loop
    // time complexity O(n), space complexity O(1)

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // creating a loop
    Solution sol;
    int length = sol.findLengthOfLoop(head);
    cout << "Length of loop: " << length << "\n";


    
    return 0;
}
