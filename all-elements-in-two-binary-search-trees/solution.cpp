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
    void solve(TreeNode* root, vector<int>&arr)
    {
        if(root==nullptr)return;
        
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;
        vector<int>ans;
        solve(root1,arr1);
        solve(root2,arr2);

        int i=0;
        int j=0;
        while(i<arr1.size() && j<arr2.size())
        {
            if(arr1[i]<=arr2[j])
            {
                ans.push_back(arr1[i]);
                i++;
            }
            else{
                ans.push_back(arr2[j]);
                j++;
            }
        }

        while(i<arr1.size())
        {
                ans.push_back(arr1[i]);
                i++;
        }
        while(j<arr2.size())
        {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }
};