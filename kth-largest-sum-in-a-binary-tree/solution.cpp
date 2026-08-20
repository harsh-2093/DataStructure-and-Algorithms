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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;

        while(q.size()>0)
        {
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                sum+=curr->val;
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
            if(pq.size()<k)
            {
                pq.push(sum);
            }
            else if(pq.top()<sum)
            {
                pq.pop();
                pq.push(sum);
            }
            level++;
        }
        if(level<k)return -1;
        return pq.top();

    }
};