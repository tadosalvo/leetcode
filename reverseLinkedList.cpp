/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // store prev null and head, ahead
        // while 
        // ahead = curr.next
        //curr next = prev
        // prev = curr
        // curr = ahead
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            ListNode* ahead = curr -> next; // ahead 2 // ahead 3 .. // ahead null
            curr -> next = prev; // points to null // points to 1 // points to 4
            prev = curr; // prev 1 curr 1 ahead 2 // prev 2 curr 2 ahead 3 // prev 5 curr 5 ahead null
            curr = ahead; // prev 1 curr 2 ahead 2 // prev 2 curr 3 ahead 3 .. // prev 4 curr 5 ahead 5 // prev 5 curr null ahead null
        } 
        return prev;
    }
};

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]