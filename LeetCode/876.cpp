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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr;
        ptr = head;
        
        int cnt = 0;
        int middle = 0;
        
        while(head){
            cnt++;
            head = head->next;
        }
        
        middle = cnt/2;
        
        for(int i=0; i<middle; i++){
            ptr = ptr->next; 
        }
        
        return ptr;
     
    }
};
