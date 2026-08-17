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
    int minDepth(TreeNode* root) {

        //bc
        if(root==nullptr)return 0;

        int Left=minDepth(root->left);
        int Right=minDepth(root->right);

        if(root->right==nullptr)
        {
            return 1+Left;
        }
        if(root->left==nullptr)
        {
            return 1+Right;
        }
        return 1+ min(Left,Right);
    }
};