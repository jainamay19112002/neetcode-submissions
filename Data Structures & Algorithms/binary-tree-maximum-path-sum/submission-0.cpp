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
    int maxisum;
    int solvingmaxipathsum(TreeNode*root){
        if(root==nullptr)
        return 0;

        int l=solvingmaxipathsum(root->left);
        int r=solvingmaxipathsum(root->right);

        int foundansatlowerlevel=root->val+l+r;
        int ifonlyrootisans=root->val;
        int eitherleftorrightisgood=root->val+max(l,r);

        maxisum=max({maxisum,foundansatlowerlevel,ifonlyrootisans,eitherleftorrightisgood});

        return max(ifonlyrootisans,eitherleftorrightisgood);
    }
    int maxPathSum(TreeNode* root) {
        maxisum=INT_MIN;
        solvingmaxipathsum(root);
        return maxisum;

    }
};
