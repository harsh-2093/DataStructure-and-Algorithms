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
    int index=0;
    int findVal(int val,vector<int>& inorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==val)return i;
        }
        return -1;
    }
    
    TreeNode* dfs(int start,int end,vector<int>& preorder,vector<int>& inorder)
    {
        if(start>end)return nullptr;

        TreeNode* root=new TreeNode(preorder[index]);
        index++;
        int root_idx=findVal(root->val,inorder);

        root->left=dfs(start,root_idx-1,preorder,inorder);
        root->right=dfs(root_idx+1,end,preorder,inorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start=0;
        int end=preorder.size()-1;
        return dfs(start,end,preorder,inorder);
    }
};