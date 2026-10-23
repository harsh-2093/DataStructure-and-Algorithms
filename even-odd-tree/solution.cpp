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
    bool even_odd=true;
    int height(TreeNode* root)
    {
        if(root==nullptr)return 0;

        int l_max=height(root->left);
        int r_max=height(root->right);
        return (max(l_max,r_max)+1);
    }
    void dfs(TreeNode* root, vector<int>&mpp,int level)
    {
        if(root==nullptr)return;

        if(level%2==0)
        {
            if(root->val%2==0 ||mpp[level]>=root->val)
            {
                even_odd=false;
            }
            mpp[level]=root->val;
        }
        else
        {
            if(root->val%2!=0 ||mpp[level]<=root->val)
            {
                even_odd=false;
            }
            mpp[level]=root->val;
        }
        dfs(root->left,mpp,level+1);
        dfs(root->right,mpp,level+1);
    }

    bool isEvenOddTree(TreeNode* root) {
        int n=height(root);
        vector<int>mpp(n,0);
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                mpp[i]=INT_MIN;
            }
            else
            {
                mpp[i]=INT_MAX
                ;
            }
        }
        dfs(root,mpp,0);
        return even_odd;

    }
};