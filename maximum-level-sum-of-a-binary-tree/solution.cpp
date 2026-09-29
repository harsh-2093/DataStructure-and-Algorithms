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
    int maxLevelSum(TreeNode* root) {
        int max_level=0;
        int max_value=INT_MIN;

        queue<TreeNode* >q;
        q.push(root);
        int level=1;

        while(q.size()>0)
        {
            int sum=0;
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;

                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
            }
            if(sum>max_value)
            {
                max_value=sum;
                max_level=level;
            }
            level++;
        }
        return max_level;
    }
};