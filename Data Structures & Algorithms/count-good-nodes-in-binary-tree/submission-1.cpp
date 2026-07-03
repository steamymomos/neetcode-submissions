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
    int count=0;
    void dfs(TreeNode* root,int mx){
        if(!root)return;
        if(mx<=root->val){
            mx=root->val;
            count++;
        }
        dfs(root->left,mx);
        dfs(root->right,mx);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root,-101);
        return count;
    }
};
