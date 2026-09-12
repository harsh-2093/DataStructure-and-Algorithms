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
    bool ispalindrome(vector<int>&temp)
    {
        int left=0;
        int right=temp.size()-1;
        while(left<=right)
        {
            if(temp[left]!=temp[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return{};
        queue<TreeNode*>q;
        q.push(root);

        while(q.size()>0)
        {
            vector<int>temp;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(curr==nullptr)
                {
                    temp.push_back(-101);
                    continue;
                }
                temp.push_back(curr->val);
                
                if(curr->left!=nullptr)
                {
                    q.push(curr->left);
                }
                else{
                    q.push(nullptr);
                }
                if(curr->right!=nullptr)
                {
                    q.push(curr->right);
                }
                else
                {
                    q.push(nullptr);
                }

            }
            if(ispalindrome(temp)==false)
            {
                return false;
            }

        }
        return true;

    }
};