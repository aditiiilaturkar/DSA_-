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
    ListNode* mergeLists(ListNode*head1, ListNode* head2){
        ListNode* head = new ListNode(0);
        ListNode* curr=head;

        while(head1 || head2){
            if(head1 && head2 && head1->val<=head2->val){
                curr->next=head1;
                head1=head1->next;
                curr=curr->next;
            }else if(head1 && head2 && head1->val>head2->val){
                curr->next=head2;
                head2=head2->next;
                curr=curr->next;
            }else if(head1){
                curr->next=head1;
                head1=head1->next;
                curr=curr->next;
            }else{
                curr->next=head2;
                head2=head2->next;
                curr=curr->next;
            }
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i=0;
        if(lists.size() < 2) {
            return lists.size() ? lists[0] : NULL;
        };
        ListNode* newList = mergeLists(lists[i],lists[i+1]);
        i+=2;
        while(i<lists.size()){
            newList = mergeLists(newList,lists[i]);
            i+=1;
        }
        return newList;
    }
};