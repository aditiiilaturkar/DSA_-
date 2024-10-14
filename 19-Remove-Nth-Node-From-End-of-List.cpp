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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int len = 0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        if(len == n) {
            head = head->next;
            return head;
        };
        curr = head;
        int i = 0;
       
        while(curr!=NULL){
            if(i>=(len-n-1)){ 
                if(curr->next!=NULL)
                    curr->next = curr->next->next;
                else
                     curr->next = NULL;
                break;
            }
            curr = curr->next;
            i++;
        }
        return head;
    }
};