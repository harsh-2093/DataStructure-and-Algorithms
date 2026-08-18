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
    vector<string>ans;
    void solve(TreeNode* root,string curr)
    {
        if(root==nullptr)
        {
            return;
        }

        
        if(root->left==nullptr && root->right==nullptr)
        {
            curr+=to_string(root->val);
            ans.push_back(curr);
            return;
        }
        curr+=to_string(root->val);
        curr+="->";

        
        solve(root->left,curr);
        solve(root->right,curr);


    }

    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root,"");
        return ans;
    }
};