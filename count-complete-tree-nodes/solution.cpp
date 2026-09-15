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
    int R_height(TreeNode * root)
    {
        if(root==nullptr)return 0;

        int left=R_height(root->right);

        return 1+left;
    }
    int L_height(TreeNode * root)
    {
        if(root==nullptr)return 0;

        int left=L_height(root->left);

        return 1+left;
    }
    int solve(TreeNode* root)
    {
        if(root==nullptr)return 0;

        int left=L_height(root->left);
        int right=R_height(root->right);

        if(left==right)
        {
            return pow(2,left+1)-1;
        }

        int left_nod=solve(root->left);
        int right_nod=solve(root->right);

        return 1+left_nod+right_nod;
    }
    int countNodes(TreeNode* root) {
        return solve(root);
    }
};