/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void dfs(TreeNode* root, map<TreeNode*,TreeNode*>&mpp)
    {
        if(root==nullptr)return;

        if(root->left!=nullptr)
        {
            mpp[root->left]=root;
        }
        dfs(root->right,mpp);
        if(root->right!=nullptr)
        {
            mpp[root->right]=root;
        }
        dfs(root->left,mpp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mpp;
        dfs(root,mpp);
        set<TreeNode*> visited;
        visited.insert(target);
        queue<TreeNode*>q;
        q.push(target);
        int level=0;

        while(q.size()>0)
        {
            vector<int>ans;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                ans.push_back(curr->val);
                q.pop();
                if(curr->left!=nullptr && !visited.count(curr->left))
                {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if(curr->right!=nullptr&& !visited.count(curr->right))
                {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if(mpp.find(curr)!=mpp.end()&& !visited.count(mpp[curr]))
                {
                    q.push(mpp[curr]);
                    visited.insert(mpp[curr]);
                }
            }
            if(level==k)return ans;
            level++;
           
        }
        return {};
    }
};