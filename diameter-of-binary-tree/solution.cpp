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
    int max_dia=INT_MIN;
    int  solve(TreeNode* root)
    {
        //base case
        if(root==nullptr)return 0;

        int Left=solve(root->left);
        int Right=solve(root->right);

        max_dia= max(max_dia,Left+Right);

        return 1+ max(Left,Right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return max_dia;
        
    }
};