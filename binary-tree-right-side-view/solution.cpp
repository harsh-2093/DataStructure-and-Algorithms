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
    int total_h=0;
    vector<int>ans;
    int height(TreeNode* root)
    {
        if(root==nullptr)return 0;

        int Left=height(root->left);
        int Right=height(root->right);
        
        return 1+max(Left,Right);
    }   
    

    void solve(TreeNode* root,int depth)
    {
        if(root==nullptr)return ;


        if(depth==ans.size())
        {
            ans.push_back(root->val);
        }
        solve(root->right,depth+1);
        solve(root->left,depth+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)return {};
        total_h=height(root);
        solve(root,0);
        return ans;
    }
};