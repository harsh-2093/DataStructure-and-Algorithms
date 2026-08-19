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
    vector<int>ans;
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        queue<TreeNode*>q;
        q.push(root);


        while(q.size()>0)
        {
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                temp.push_back(curr->val);
                q.pop();

                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
            ans.push_back(temp.back());

        }
        return ans;
    }
};