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
    TreeNode* addroot(TreeNode* root,int curr, int val, int depth)
    {
        if(root==nullptr)return nullptr;

        if(curr==depth-1)
        {
            TreeNode* prev_left=root->left;
            TreeNode* prev_right=root->right;

                TreeNode* node=new TreeNode(val);
                root->left=node;
                node->left=prev_left;
            

                TreeNode* node2=new TreeNode(val);
                root->right=node2;
                node2->right=prev_right;
                return root;

        }
        root->left=addroot(root->left,curr+1,val,depth);
        root->right=addroot(root->right,curr+1,val,depth);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* node =new TreeNode(val);
            node->left=root;
            return node;
        }

        int curr=1;
        addroot(root,curr,val,depth);
        return root;
    }
};