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
    bool result=false;
    void solve(TreeNode* root,int targetSum,int& sum)
    {
        if(root==nullptr)return;
        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr)
        {
            if(sum==targetSum)
            {
                result=true;

            }
            sum-=root->val;
            return;
        }

        solve(root->left,targetSum,sum);
        solve(root->right,targetSum,sum);
        sum-=root->val;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        solve(root,targetSum,sum);
        return result;
    }
};