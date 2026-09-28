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
    int max_len=0;
    void dfs(TreeNode* root,int dir,int cnt)
    {
         
        if(root==nullptr)return;
        max_len=max(max_len,cnt);

        if(dir==-1)
        {
            dfs(root->left,dir*-1,cnt+1);
             dfs(root->right,dir,1);
        }
        else{
            dfs(root->right,dir*-1,cnt+1);
            dfs(root->left,dir,1);
        }
        
        

    }
    int longestZigZag(TreeNode* root) {
        dfs(root,-1,0);
        return max_len;
    }
};