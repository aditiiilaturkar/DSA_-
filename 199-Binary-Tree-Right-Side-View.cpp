/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>pq;
        if(root==NULL) return {};
        pq.push(root);
        vector<int> ans;
                
        while(!pq.empty()){
            int size = pq.size();
            while(size>0){
                TreeNode* curr = pq.front();
                if(curr->left) pq.push(curr->left);
                if(curr->right) pq.push(curr->right);
                pq.pop();
                size--;
                if(size==0) ans.push_back(curr->val);
            }
        }
        return ans;
    }
};