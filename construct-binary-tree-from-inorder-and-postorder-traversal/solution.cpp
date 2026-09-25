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
    
    TreeNode* dfs(int start,int end,vector<int>& postorder,vector<int>& inorder)
    {
        if(start>end)return nullptr;

        TreeNode* root=new TreeNode(postorder[index]);
        index--;
        int root_idx=findVal(root->val,inorder);
       
        root->right=dfs(root_idx+1,end,postorder,inorder);
        root->left=dfs(start,root_idx-1,postorder,inorder);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index=postorder.size()-1;
        int  start=0;
        int end=index;
        return dfs(start,end,postorder,inorder);

    }
};