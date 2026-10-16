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
    int moves=0;
    int dfs(TreeNode* root)
    {
        if(root==nullptr)return 0;

        int e_lnode=dfs(root->left);
        int e_rnode=dfs(root->right);

        int no_coin=(e_lnode+e_rnode+root->val)-1;

        moves+=abs(no_coin);
        return no_coin;

    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    } 
};