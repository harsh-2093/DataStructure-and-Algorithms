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
    vector<TreeNode*>ans;
    TreeNode* root_node=nullptr;
    TreeNode* solve(TreeNode* root,unordered_set<int>&mpp)
    {
        if(root==nullptr)return nullptr;

        TreeNode*left=solve(root->left,mpp);
        TreeNode*right=solve(root->right,mpp);
        root->left=left;
        root->right=right;

        if(mpp.find(root->val)!=mpp.end())
        {
            if(left!=nullptr)
            {
                ans.push_back(left);
            }
            if(right!=nullptr)
            {
                ans.push_back(right);
            }
            return nullptr;
        }
        if(root_node==root && mpp.find(root->val)==mpp.end())
        {
            ans.push_back(root);
        }

        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>mpp;
        for(int e:to_delete)
        {
            mpp.insert(e);
        }
        root_node=root;

        solve(root,mpp);
        return ans;
    }
};