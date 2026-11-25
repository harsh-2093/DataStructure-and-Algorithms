/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int total_sum = 0;

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr)
            return;

        if (root->left == nullptr && root->right == nullptr) {
            sum = sum * 10;
            sum += root->val;
            total_sum += sum;
            return;
        }

        sum = sum * 10;
        sum += root->val;
        dfs(root->left, sum);

        dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum);
        return total_sum;
    }
};