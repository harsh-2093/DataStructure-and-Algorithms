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
    map<int,int>mpp;
    //<value,freq>

    void solve(TreeNode* root)
    {
        if(root==nullptr)return;
        mpp[root->val]++;
        solve(root->left);
        solve(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        vector<int>ans;
        solve(root);
        int freq=-1;
        auto it=mpp.begin();

        while(it!=mpp.end())
        {
            freq=max(freq,it->second);
            ++it;
        }
        it=mpp.begin();
        while(it!=mpp.end())
        {
            if(it->second==freq)
            {
                ans.push_back(it->first);
            }
            ++it;
        }
        return ans;
    }
};