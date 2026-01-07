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
private:
    ListNode* Reverse(ListNode* head){
        if(head == nullptr or head -> next == nullptr) return head;
        ListNode* prev = head;
        ListNode* curr = head -> next;
        prev -> next = nullptr;
        while(curr != nullptr){
            ListNode* temp = curr;
            curr = curr -> next;
            temp -> next = prev;
            prev = temp;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) { 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next != nullptr and fast -> next -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        ListNode* head2 = Reverse(slow -> next);
        ListNode* resto = head2;
        ListNode* head1 = head;
        bool ans = true;
        while(head1 != nullptr and head2 != nullptr){
            if(head1 -> val != head2 -> val){
                ans = false;
                break;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        slow -> next = Reverse(resto);
        return ans;

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
    vector<int> nums = {1,2,3,2,1};
    int n = nums.size();
    ListNode* head = new ListNode(nums[0]);
    ListNode* temp = head;
    for(int i=1;i<n;i++){
        temp -> next = new ListNode(nums[i]);
        temp = temp -> next;
    }
    // Check if linked list is palindrome
    // Approach:            
    // 1. Find middle of linked list using tortoise and hare algorithm
    // 2. Reverse second half of linked list
    // 3. Compare first half and reversed second half
    // 4. If both halves are same then linked list is palindrome else not palindrome
    // 5. (Optional) Restore the original linked list by reversing the second half again and attaching it back
    Solution sol;
    bool result = sol.isPalindrome(head);
    cout << "Linked List: ";
    sol.PrintLinkedList(head);
    if(result) cout << "Linked List is Palindrome" << endl;
    else cout << "Linked List is not Palindrome" << endl;
    cout << "Restored Linked List: ";
    sol.PrintLinkedList(head);
    
    
    
    return 0;
}
