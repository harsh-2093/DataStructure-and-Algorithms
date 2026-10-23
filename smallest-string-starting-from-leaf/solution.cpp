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
    string ans="{";
    void dfs(TreeNode* root,string current)
    {
        if(root==nullptr)return;
        current+='a'+root->val;
        if(root->left==nullptr && root->right==nullptr)
        {
            reverse(current.begin(),current.end());
            if(current<ans)
            {
                ans=current;
            }
            cout<<current<<endl;
            return;
        }
        dfs(root->left,current);
        dfs(root->right,current);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        // for(string i:ans)
        // {
        //     return i;
        // }
        return ans;
    }
};