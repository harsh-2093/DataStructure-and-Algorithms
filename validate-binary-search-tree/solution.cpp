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
    long long prev=LLONG_MIN;
    bool dfs(TreeNode*root)
    {
        
        if(root==nullptr)
        {
            return true;
        }

        if(dfs(root->left)==false)
        {
            return false;
        }

        if(prev!=LLONG_MIN && root->val <=prev)
        {
            return false;
        }
        prev=root->val;
        return dfs(root->right);

    }
    bool isValidBST(TreeNode* root) {
        // long long prev=LLONG_PREV;
        return dfs(root);

    }
};