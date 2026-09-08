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
    vector<vector<int>>ans;
    void solve(TreeNode* root, int targetSum,  vector<int>&temp,int sum)
    {
        if(root==nullptr)return;
        if(root->left==nullptr && root->right==nullptr)
        {
            sum+=root->val;
            temp.push_back(root->val);
            if(sum==targetSum)
            {
                ans.push_back(temp);
            }
            temp.pop_back();
            sum-=root->val;
            return;
        }
        sum+=root->val;
        temp.push_back(root->val);

        solve(root->left,targetSum,temp,sum);
        solve(root->right,targetSum,temp,sum);
        temp.pop_back();
        sum-=root->val;

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,temp,0);
        return ans;
    }
};