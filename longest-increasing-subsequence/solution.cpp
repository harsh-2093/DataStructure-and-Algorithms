class Solution {
public:
    int dfs(vector<int>& nums,int index,int prev,vector<vector<int>>&dp)
    {
        if(index>nums.size()-1)
        {
            return 0;
        }

        if(prev==-1)
        {
            if(dp[index][prev+1]!=-1)return dp[index][prev+1];
            int take=1+dfs(nums,index+1,index,dp);
            int leave=dfs(nums,index+1,prev,dp);
            dp[index][prev+1]=max(take,leave);
            return max(take,leave);
        }
        else
        {
            if(nums[index]>nums[prev])
            {
                if(dp[index][prev+1]!=-1)return dp[index][prev+1];
                int take=1+dfs(nums,index+1,index,dp);
                int leave=dfs(nums,index+1,prev,dp);
                dp[index][prev+1]=max(take,leave);
                return max(take,leave);
            }
            else
            {
                if(dp[index][prev+1]!=-1)return dp[index][prev+1];
                int leave=dfs(nums,index+1,prev,dp);
                dp[index][prev+1]=leave;
                return leave;
            }

        }
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return dfs(nums,0,-1,dp);
    }
};