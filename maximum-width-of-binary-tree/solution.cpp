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
    typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*,ll>>q;
        q.push_back({root,0});
        int  max_width=0;
        while(q.size()>0)
        {
            long long first_idx=q.front().second;
            long long back_idx=q.back().second;
            max_width=max(max_width,(int)(back_idx-first_idx)+1);
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front().first;
                ll idx = q.front().second - first_idx;
                q.pop_front();

                if(curr->left!=nullptr)
                {
                    q.push_back({curr->left,2*idx+1});
                }
                if(curr->right!=nullptr)
                {
                    q.push_back({curr->right,2*idx+2});
                }
            }
        }
        return max_width;
    }
};