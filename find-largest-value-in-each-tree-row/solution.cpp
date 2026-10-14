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
    void bfs(queue<TreeNode*>&q,vector<int>&result)
    {
        while(q.size()>0)
        {
            int n=q.size();
            int max_val=INT_MIN;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr->val>max_val)
                {
                    max_val=curr->val;
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
            result.push_back(max_val);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)return {};
        vector<int>result;
        queue<TreeNode*>q;

        q.push(root);
        bfs(q,result);
        return result;
    }
};