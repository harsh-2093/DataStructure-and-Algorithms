/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    TreeNode* ans =nullptr;
    int solve(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==nullptr)return 0;
        int cnt=0;
        if(root==p || root==q)
        {
            cnt++;
        }

        int left=solve(root->left,p,q);
        int right=solve(root->right,p,q);

        if(cnt+left+right>1)
        {
            ans=root;
            return 0;
        }

        return cnt+left+right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};