class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),1);
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    int seq=dp[i];
                    dp[i]=max(dp[j]+1,seq);
                    ans=max(dp[i],ans);

                }

            }
        }
        return ans;
    }
};