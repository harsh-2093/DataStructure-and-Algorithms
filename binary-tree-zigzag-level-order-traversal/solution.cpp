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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return{};
        queue<TreeNode*>q;
        int flag=1;
        q.push(root);
        flag=0;

        while(q.size()>0)
        {
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                temp.push_back(curr->val);

                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }

            }
            if(flag==1)
            {
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                flag=0;
            }
            else{
                ans.push_back(temp);
                flag=1;
            }
        }
        return ans;


    }
};