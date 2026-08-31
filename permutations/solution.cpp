class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,vector<int>&curr,set<int>&mpp)
    {
        if(curr.size()==nums.size())
        {
            ans.push_back(curr);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(mpp.find(i)!=mpp.end())
            {
                continue;
            }
            mpp.insert(i);
            curr.push_back(nums[i]);
            solve(nums,curr,mpp);
            mpp.erase(i);
            curr.pop_back();

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        set<int>mpp;
        vector<int>curr;
        solve(nums,curr,mpp);
        return ans;
    }
};