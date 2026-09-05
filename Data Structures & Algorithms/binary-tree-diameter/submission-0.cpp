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
    int maxidiameter=0;
    int heightofbinarytree(TreeNode*root){
        if(root==nullptr)
        return 0;

        int leftheight=heightofbinarytree(root->left);
        int rightheight=heightofbinarytree(root->right);

        if(leftheight+rightheight>=maxidiameter){
            maxidiameter=leftheight+rightheight;
        }
        return 1+max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxidiameter=0;
        heightofbinarytree(root);
        return maxidiameter;
        
    }
};
