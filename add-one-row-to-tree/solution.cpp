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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* node =new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*>q;
        q.push(root);
        int idx=0;

        while(q.size()>0)
        {
            idx++;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();

                if(idx==depth-1)
                {
                    TreeNode* prev_left=curr->left;
                    TreeNode* prev_right=curr->right;

                    TreeNode* node=new TreeNode(val);
                    curr->left=node;
                    node->left=prev_left;
                    q.push(node);
        
                    TreeNode* node2=new TreeNode(val);
                    curr->right=node2;
                    node2->right=prev_right;
                    q.push(node2);
                }
                else
                {
                    if(curr->left!=nullptr)
                    {
                        q.push(curr->left);
                    }
                    if(curr->right!=nullptr)
                    {
                        q.push(curr->right);
                    }
                }


            }

        }
        return root;

    }
};