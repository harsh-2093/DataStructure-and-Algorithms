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
    bool ispresent(TreeNode* root)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(root->val==1)return true;
        bool left=ispresent(root->left);
        bool right=ispresent(root->right);

        return left || right;
    }
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root==nullptr)return nullptr;

        if(!ispresent(root->left))
        {
            root->left=nullptr;
        }

        if(!ispresent(root->right))
        {
            root->right=nullptr;
        }
        pruneTree(root->left);
        pruneTree(root->right);
        if(!ispresent(root->left)&& !ispresent(root->right)&& root->val==0)
        {
            return nullptr;
        }
        return root;

    }
};