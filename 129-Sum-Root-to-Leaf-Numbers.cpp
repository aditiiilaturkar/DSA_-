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
    void dfs(TreeNode* root, int& ans, string curr) {
        if(!root) return;
        curr+= to_string(root->val); //curr = 12
        if(root->left == NULL && root->right == NULL){
            ans+= stoi(curr);         
        }else{
            dfs(root->left, ans, curr);        
            dfs(root->right, ans, curr);
        }
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string curr = \\;
        dfs(root, ans, curr);
        return ans;
    }
};