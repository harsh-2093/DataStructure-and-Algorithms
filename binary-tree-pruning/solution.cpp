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
    bool isvalid(TreeNode* root)
    {
        if(root==nullptr)return false;

        bool  left=isvalid(root->left);
        bool right=isvalid(root->right);

        if(root->val==1)return true;

        return (left|| right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr)return nullptr;
        if(!isvalid(root->left))
        {
            root->left=nullptr;
        }
        if(!isvalid(root->right))
        {
            root->right= nullptr;
        }

        pruneTree(root->left);
        pruneTree(root->right);

        if(!isvalid(root->left)&& !isvalid(root->right) &&root->val==0)return nullptr;
        return root;
    }
};