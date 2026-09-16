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
    int max_diff=INT_MIN;
    void dfs(TreeNode * root ,int min_element,int max_element)
    {
        if(root==nullptr)return;

        min_element=min(root->val,min_element);
        max_element=max(root->val,max_element);
        int val1=abs(root->val-min_element);
        int val2=abs(root->val-max_element);
        max_diff=max(max_diff,max(val1,val2));

        dfs(root->left,min_element,max_element);
        dfs(root->right,min_element,max_element);

    }
    int maxAncestorDiff(TreeNode* root) {
        int min_element=INT_MAX;
        int max_element=INT_MIN;
        dfs(root,min_element,max_element);
        return max_diff;
    }
};