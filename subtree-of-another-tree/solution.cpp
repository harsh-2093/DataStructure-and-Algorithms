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
    bool isIdentical(TreeNode* root, TreeNode* subRoot)
    {
        if(root==nullptr && subRoot!=nullptr)return false;
        if(root!=nullptr&& subRoot==nullptr)return false;
        if(root==nullptr&& subRoot==nullptr)return true;

        bool Left=isIdentical(root->left,subRoot->left);
        bool Right=isIdentical(root->right,subRoot->right);
        return root->val == subRoot->val && Left && Right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr&& subRoot!=nullptr)return false;
        if(root!=nullptr&& subRoot==nullptr)return false;
        if(root==nullptr&& subRoot==nullptr)return true;

        if(root->val==subRoot->val && isIdentical(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};