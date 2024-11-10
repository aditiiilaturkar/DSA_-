/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*>mp;
    void DFS(Node* node, Node* clone_node) {
        if(!node || !clone_node) return;

        for(Node* curr: node->neighbors){
            if(mp.find(curr) == mp.end()){
               Node* new_clone = new Node(curr->val);
               mp[curr] = new_clone;
                clone_node->neighbors.push_back(new_clone);
                DFS(curr, new_clone);
            }else{
                 clone_node->neighbors.push_back(mp[curr]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        DFS(node, clone_node);
        return clone_node;
    }
};