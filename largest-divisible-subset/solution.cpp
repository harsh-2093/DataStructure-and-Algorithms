class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int>prev(nums.size(),-1);

        int ans=-1;
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {

                if(nums[i]%nums[j]==0 ||nums[j]%nums[i]==0)
                {
                    int take=dp[j]+1;
                    if(dp[i]<take)
                    {
                        prev[i]=j;
                    }
                    dp[i]=max(dp[i],take);
                }
                

            }
            if(ans<dp[i])
            {
                index=i;
            }
            ans=max(ans,dp[i]);
        }
        vector<int>result;
        while(prev[index]!=-1)
        {
            result.push_back(nums[index]);
            index=prev[index];
        }
        result.push_back(nums[index]);
        reverse(result.begin(),result.end());
        return result;
    }
};