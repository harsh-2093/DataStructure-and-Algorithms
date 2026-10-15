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
    TreeNode* start_node=nullptr;
    void find_parent(TreeNode* root, map<TreeNode*,TreeNode*>&mpp,int start){
        if(root==nullptr)return;
        if(root->val==start)
        {
            start_node=root;
        }
        if(root->left!=nullptr)
        {
            mpp[root->left]=root;
        }
        if(root->right!=nullptr)
        {
            mpp[root->right]=root;
        }

        find_parent(root->left,mpp,start);
        find_parent(root->right,mpp,start);
        
    }
    int amountOfTime(TreeNode* root, int start){
        map<TreeNode*,TreeNode*>mpp;
        find_parent(root,mpp,start);
        set<int>visited;

        queue<TreeNode*>q;
        q.push(start_node);
        visited.insert(start_node->val);
        int time=0;
        while(q.size()>0)
        {
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front();
                visited.insert(curr->val);
                q.pop();

                if(curr->left!=nullptr && visited.find(curr->left->val)==visited.end())
                {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if(curr->right!=nullptr && visited.find(curr->right->val)==visited.end())
                {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if(mpp.find(curr)!=mpp.end() && visited.find(mpp[curr]->val)==visited.end())
                {
                    q.push(mpp[curr]);
                }
            }
            time++;
        }
        return time-1;
    }
};