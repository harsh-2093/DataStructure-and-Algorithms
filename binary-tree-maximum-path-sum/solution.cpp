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
    int sum=INT_MIN;
    int solve(TreeNode* root)
    {
        if(root==nullptr)return 0;

        int left=solve(root->left);
        int right=solve(root->right);

        sum=max(sum,left+right+root->val);

        sum=max(sum,max(left,right)+root->val);

        sum=max(sum,root->val);

        return max(max(left,right)+root->val,root->val);

    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return sum;
    }
};