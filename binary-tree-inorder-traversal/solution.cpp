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

 //iterative morris traversal
class Solution {
public:
    vector<int>ans;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr=root;

        while(curr!=nullptr)
        {
            if(curr->left==nullptr)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;

                while(prev->right!=nullptr)
                {
                    prev=prev->right;
                }
                prev->right=curr;

                //break the curr left link
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=nullptr;
            }
        }
        return ans;
    }
};