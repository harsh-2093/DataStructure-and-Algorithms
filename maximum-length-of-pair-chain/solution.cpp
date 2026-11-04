class Solution {
public:
    int dfs(vector<vector<int>>& pairs,int prev,int index,vector<vector<int>>&dp)
    {
        if(index>pairs.size()-1)
        {
            return 0;

        }

        if(prev==-1)
        {
            if(dp[index][prev+1]!=-1)return dp[index][prev+1];
            int take =1+dfs(pairs,index,index+1,dp);
            int skip=dfs(pairs,prev,index+1,dp);
            dp[index][prev+1]=max(skip,take);
            return max(take,skip);
        }
        else
        {
            if(pairs[prev][1]<pairs[index][0])
            {
                 if(dp[index][prev+1]!=-1)return dp[index][prev+1];
                int take =1+dfs(pairs,index,index+1,dp);
                int skip=dfs(pairs,prev,index+1,dp);
                 dp[index][prev+1]=max(skip,take);
                return max(take,skip);
            }
            else
            {
                if(dp[index][prev+1]!=-1)return dp[index][prev+1];
                int skip=dfs(pairs,prev,index+1,dp);
                 dp[index][prev+1]=skip;
                return skip;

            }
        }


    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());    
        vector<vector<int>>dp(pairs.size(),vector<int>(pairs.size()+1,-1));
        return dfs(pairs,-1,0,dp);

    }
};