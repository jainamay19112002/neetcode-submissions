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
    unordered_map<int,int>mp;
    int preidx=0;
    TreeNode*buildingtree(vector<int>& preorder,int inleft,int inright){
        if(inleft>inright)
        return nullptr;

        int rootvalue=preorder[preidx++];
        TreeNode*root=new TreeNode(rootvalue);
        int index=mp[rootvalue];
        root->left=buildingtree(preorder,inleft,index-1);
        root->right=buildingtree(preorder,index+1,inright);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildingtree(preorder,0,inorder.size()-1);  
    }
};
