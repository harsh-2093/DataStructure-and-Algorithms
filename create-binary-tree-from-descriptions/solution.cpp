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
    TreeNode* dfs(int root,unordered_map<int,pair<int,int>>&mpp)
    {
        if(root==-1)
        {
            return nullptr;
        }

        TreeNode* node=new TreeNode(root);
                    if(mpp.find(root) == mpp.end())
        return node;
        node->left=dfs(mpp[root].first,mpp);
        node->right=dfs(mpp[root].second,mpp);

        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<int,int>>mpp;
        unordered_set<int>P;
        unordered_set<int>C;

        // step1:map the description
        for(auto n:descriptions)
        {
            int parent=n[0];
            int child=n[1];
            int isleft=n[2];
            P.insert(parent);
            C.insert(child);

            if(mpp.find(parent) == mpp.end())
            mpp[parent] = {-1, -1};

            if(isleft==1)
            {
                mpp[parent].first=child;
            }
            else
            {
                mpp[parent].second=child;
            }
        }

        //step2: find root
        int root=-1;
        for(auto r:P)
        {
            if(C.find(r)==C.end())
            {
                root=r;
                break;
            }

        }

        //step3:build the tree
        return dfs(root,mpp);
    }
};