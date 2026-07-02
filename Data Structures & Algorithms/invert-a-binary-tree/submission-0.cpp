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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto roo=q.front();
            q.pop();
            if(roo->left && roo->right){
                auto temp=roo->left;
                roo->left=roo->right;
                roo->right=temp;
                q.push(roo->right);
                q.push(roo->left);
            }
            else if(roo->left){
                roo->right=roo->left;
                roo->left=nullptr;
                q.push(roo->right);
            }
            else if(roo->right){
                roo->left=roo->right;
                roo->right=nullptr;
                q.push(roo->left);
            }
        }
        return root;
    }
};
