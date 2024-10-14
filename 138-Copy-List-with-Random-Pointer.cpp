/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* head2 = new Node(-1);
        map<Node*, Node*>mp;
        Node* curr = head;
        while(curr != NULL){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }      
        curr = head;
        while(curr!= NULL){
            Node* temp = mp[curr];
            temp->next = mp[curr->next];
            temp->random = mp[curr->random];
            curr=curr->next;
        }

       
        head2=mp[head];
        return head2;
    }
};