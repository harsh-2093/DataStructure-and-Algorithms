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
    void dfs(TreeNode* root,string current,vector<string>&res)
    {
          if (root==nullptr)return;
           current+=to_string(root->val);
         if(root->left==nullptr&&root->right==nullptr)
        {
            res.push_back(current);
            return;
        }
        current+="->";

      
       
       
        dfs(root->left,current,res);
        dfs(root->right,current,res);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
     vector<string>res;
     string current="";
    dfs(root,current,res);
    return res;
    }
};