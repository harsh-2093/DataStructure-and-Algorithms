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
    int countNode(TreeNode* root)
    {
        if(root==nullptr)return 0;

        int left=countNode(root->left);
        int right=countNode(root->right);

        return 1+left+right;
    }
    bool solve(TreeNode* root,int index,int totalNodes)
    {
        if(root==nullptr)return true;
        if(index>totalNodes)return false;
        bool left=solve(root->left,2*index,totalNodes);
        bool right=solve(root->right,2*index+1,totalNodes);

        return left && right ;
    }
    bool isCompleteTree(TreeNode* root) {
        int totalNodes=countNode(root);
        return solve(root,1,totalNodes);
    }
};