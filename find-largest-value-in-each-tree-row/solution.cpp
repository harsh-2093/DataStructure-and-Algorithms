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
    void dfs(TreeNode* root, map<int,int>&mpp,int level)
    {
        if(root==nullptr)return;

        if(mpp.find(level)==mpp.end())
        {
            mpp[level]=root->val;
        }
        else
        {
            if(root->val>mpp[level])
            {
                mpp[level]=root->val;
            }
        }

        dfs(root->left,mpp,level+1);
        dfs(root->right,mpp,level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        map<int,int>mpp;
        dfs(root,mpp,0);
        vector<int>result;
        auto it=mpp.begin();
        while(it!=mpp.end())
        {
            result.push_back(it->second);
            ++it;
        }
        return result;
    }
};