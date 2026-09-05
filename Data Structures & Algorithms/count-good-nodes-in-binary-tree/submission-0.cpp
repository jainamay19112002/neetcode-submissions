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
    int goodie=0;
    void dfs(TreeNode*root,int maxsofar){
        if(root==nullptr)
        return;

        if(root->val>=maxsofar)
        goodie++;

        maxsofar=max(maxsofar,root->val);

        dfs(root->left,maxsofar);
        dfs(root->right,maxsofar);
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr)
        return 0;

        dfs(root,root->val);
        return goodie;
        
    }
};
