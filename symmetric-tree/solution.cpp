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
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if(a==nullptr && b==nullptr)return true;
        if(a==nullptr && b!=nullptr)return false;
        if(a!=nullptr && b==nullptr)return false;

        bool left=isSameTree(a->left,b->right);
        bool right=isSameTree(a->right,b->left);
        
        if(a->val!=b->val)return false;

        return left && right;

    }
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left,root->right);
    }
};