
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
    ListNode* KNode(ListNode* x,int k){
        for(int i=1;i<k;i++){
            x = x -> next;
            if(x == nullptr) return nullptr;
        }
        return x;
    }
    ListNode* Reverse(ListNode* start, ListNode* finish){
        ListNode* prevx = nullptr;
        ListNode* tp = start;
        while(tp != finish){
            ListNode* new_tp = tp -> next;
            tp -> next = prevx;
            prevx = tp;
            tp = new_tp;
        }
        tp -> next = prevx;
        return finish;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy;
        while(temp != nullptr){
            ListNode* KthNode = KNode(temp,k);
            if(KthNode == nullptr){
                prev -> next = temp;
                break;

            }
            else {
                ListNode* new_temp = KthNode -> next;
                KthNode -> next = nullptr;
                ListNode* new_head = Reverse(temp,KthNode);
                prev -> next = new_head;
                prev = temp; 
                prev -> next = new_temp;
                temp = new_temp;

            }
        }
        return dummy -> next;

    }
};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    /*
    Given the head of a singly linked list containing integers, 
    reverse the nodes of the list in groups of k and return the head of the modified list. 
    If the number of nodes is not a multiple of k, 
    then the remaining nodes at the end should be kept as is and not reversed.
    Do not change the values of the nodes, only change the links between nodes.
    */
        ListNode* head = new ListNode(1);
        head -> next = new ListNode(2);
        head -> next -> next = new ListNode(3);
        head -> next -> next -> next = new ListNode(4);
        head -> next -> next -> next -> next = new ListNode(5);
        cout << "Original Linked List: ";
        ListNode* temp = head;
        while(temp != nullptr){
            cout << temp -> val << " ";
            temp = temp -> next;
        }
        cout << endl;
        int k = 2;
        Solution obj;
        ListNode* new_head = obj.reverseKGroup(head,k);
        temp = head;
        cout << "Linked List after reversing in groups of k = " << k << ": ";
        while(new_head != nullptr){
            cout << new_head -> val << " ";
            new_head = new_head -> next;
        }
        cout << endl;
    
    return 0;
}