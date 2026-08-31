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
            int pos=curr.size()+1;
            if(nums[i]%pos ==0 || pos%nums[i]==0)
            {
                mpp.insert(i);
                curr.push_back(nums[i]);
                solve(nums,curr,mpp);
                mpp.erase(i);
                curr.pop_back();
            }


        }
    }
    int countArrangement(int n) {
        vector<int>nums;
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        set<int>mpp;
        vector<int>curr;
        solve(nums,curr,mpp);
        return ans.size();
    }
};