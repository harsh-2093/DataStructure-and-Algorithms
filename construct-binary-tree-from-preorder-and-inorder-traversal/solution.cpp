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
    int find_indx(int value,vector<int>& inorder)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i]==value)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(int start,int end,vector<int>& preorder, vector<int>& inorder)
    {
        if(start>end)return nullptr;

        TreeNode* root=new TreeNode(preorder[index]);
        int root_indx=find_indx(preorder[index],inorder);
        index++;
        
        root->left=solve(start,root_indx-1,preorder,inorder);
        root->right=solve(root_indx+1,end,preorder,inorder);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,preorder.size()-1,preorder,inorder);
    }
};