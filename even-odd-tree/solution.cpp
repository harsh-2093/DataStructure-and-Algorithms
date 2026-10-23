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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(q.size()>0)
        {
            int n=q.size();
            int prev_odd=INT_MAX;
            int prev_even=INT_MIN;

            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(level%2==0)
                {
                    if(curr->val%2==0 || curr->val<=prev_even)return false;
                    prev_even=curr->val;
                }
                else
                {
                    if(curr->val%2!=0 || curr->val>=prev_odd)return false;
                    prev_odd=curr->val;
                }
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
            level++;
        }
        return true;
    }
};