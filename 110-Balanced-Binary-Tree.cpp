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
    pair<bool, int>dfs2(TreeNode* root) {
        if(!root) return {true, 0};
        pair<bool, int> leftHeight = dfs2(root->left);
        pair<bool, int> rightHeight = dfs2(root->right);
        bool balanced = leftHeight.first && rightHeight.first && abs(leftHeight.second-rightHeight.second) <= 1;
        return {balanced, 1+max(leftHeight.second,rightHeight.second)};
    }


    long long dfs(TreeNode* root){
        if(!root) return 0;

        long long leftHeight = 1+dfs(root->left);
        long long rightHeight = 1+dfs(root->right);

        if(abs(leftHeight-rightHeight)<=1) {
            return max(leftHeight,rightHeight);
        }
        return INT_MAX;
    }

    bool isBalanced(TreeNode* root) {
        // pair<bool, int>ans;
        // ans = dfs2(root);
        // return ans.first;


        long long ans = dfs(root);
        if(ans>=INT_MAX) return false;
        return true;
    }
};