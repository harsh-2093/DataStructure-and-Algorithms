/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };`
 */
class Solution {
public:
    int ans=0;
    pair<int,int> dfs(TreeNode * root){
        if(root==nullptr)return {0,0};

        pair<int,int>Lnode=dfs(root->left);
        pair<int,int>Rnode=dfs(root->right);
        
        int Total_sum=root->val+Lnode.second+Rnode.second;
        int Total_node=Lnode.first+Rnode.first+1;

        if((Total_sum/Total_node)==root->val)ans++;

        return {Total_node,Total_sum};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};