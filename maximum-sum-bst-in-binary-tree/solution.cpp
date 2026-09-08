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
    struct Info {
        bool isBst;
        int mini;
        int maxi;
        int sum;
    };
    int ans=0;
    Info solve(TreeNode* root)
    {
        if(root==nullptr)
        {
            return {true,INT_MAX,INT_MIN,0};
        }

        Info left=solve(root->left);
        Info right=solve(root->right);

        if(left.isBst==true && right.isBst==true&& root->val>left.maxi && root->val<right.mini)
        {
            int maxi=max(root->val,right.maxi);
            int mini=min(root->val,left.mini);
            int val=left.sum+right.sum+root->val;
            ans=max(val,ans);
            return {true,mini,maxi,val};
        }
        return {false,0,0,0};
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};