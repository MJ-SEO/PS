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
        
        ListNode* ptr = NULL;
        ListNode* pre_ptr = NULL;
        
        while(head){
            ptr = head->next;
            head->next = pre_ptr;
            pre_ptr = head;
            head = ptr;     
        }
        
        return pre_ptr;
          
    }
};
