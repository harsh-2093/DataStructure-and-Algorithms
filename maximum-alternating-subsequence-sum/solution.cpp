class Solution {
public:
    long long  dfs(vector<int>& nums,int index,int sign, vector<vector<long long>>&dp)
    {
        //something off
        if(index>=nums.size())
        {
            return 0;
        }
        if(sign==1)
        {
            if(dp[index][0]!=-1)return dp[index][0];
        }
        else
        {
            if(dp[index][1]!=-1)return dp[index][1];

        }

        long long leave= dfs(nums,index+1,sign,dp);

        long long val=nums[index]*sign;
        long long  take= val+dfs(nums,index+1,sign*-1,dp);

        
        if(sign==1)
        {
            dp[index][0]=max(leave,take);
        }
        else
        {
           dp[index][1]=max(leave,take);
        }
        
        return max(leave,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>dp(nums.size(),vector<long long>(2,-1));
        return dfs(nums,0,1,dp);        
    }
};