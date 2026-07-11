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
         if(root==nullptr)return {};
         int ltor=1;
         vector<vector<int>>result;
         queue<TreeNode*>q;
         q.push(root);

         while(!q.empty())
         {
            int levelsize=q.size();
            vector<int>curr_level;
            for(int i=0;i<levelsize;i++)
            {
                
                TreeNode*node=q.front();
                q.pop();
                curr_level.push_back(node->val);
                if(node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if(node->right!=nullptr)
                {
                    q.push(node->right);
                }

            }
            if(ltor)
            {
                result.push_back(curr_level);
                ltor=0;

            }
            else
            {
                reverse(curr_level.begin(),curr_level.end());
                result.push_back(curr_level);
                ltor=1;
            }
           

         }
         return result;
        
    }
};