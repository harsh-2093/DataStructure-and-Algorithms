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
    int ans=0;
    void dfs(TreeNode* root,vector<int>&mpp)
    {
        if(root==nullptr)
        {
            return;
        }

        mpp[root->val]++;
        if(root->right==nullptr && root->left==nullptr)
        {
            int odd=0;
            for(int i=0;i<=9;i++)
            {
                if(mpp[i]%2!=0){
                    odd++;
                }
            }
            if(odd<=1)
            {
                ans++;
            }
        }

        dfs(root->left,mpp);
        dfs(root->right,mpp);

        mpp[root->val]--;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>mpp(10,0);
        dfs(root,mpp);
        return ans;

    }
};