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
    void getLeaf(TreeNode*root,vector<int>&temp)
    {
    
        if(root==nullptr)return;

        if(root->left==nullptr && root->right==nullptr)
        {
            temp.push_back(root->val);
        }

        getLeaf(root->left,temp);
        getLeaf(root->right,temp);

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>temp1;
        vector<int>temp2;

        getLeaf(root1,temp1);
        getLeaf(root2,temp2);
        if(temp1==temp2)return true;
        return false;



    }
};