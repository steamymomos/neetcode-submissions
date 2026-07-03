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
    vector<int> ans;
    int count=0;
    void dfs(TreeNode* root,int depth){
        if(!root)return;
        if(ans.back()<=root->val){
            ans.push_back(root->val);
            count++;
        }
        dfs(root->left,depth+1);
        dfs(root->right,depth+1);
        if(ans.back()==root->val)ans.pop_back();
    }
public:
    int goodNodes(TreeNode* root) {
        ans={root->val};
        dfs(root,0);
        return count;
    }
};
