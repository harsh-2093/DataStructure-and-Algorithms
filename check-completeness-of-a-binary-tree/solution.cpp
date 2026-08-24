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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

         int flag=0;
        while(q.size()>0)
        {
            // vector<int>temp;
            int n=q.size();
           
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr==nullptr)
                {
                    flag=1;
                }
                if(flag==1 && curr!=nullptr)
                {
                    return false;
                }
                if(curr!=nullptr)
                {
                    q.push(curr->left);
                    q.push(curr->right);       
                }

            }
        }
        return true;
    }
};