class Solution {
public:
    const int MOD = 1e9 + 7;
    int  dfs(int n,int m,int k,int prev,int index,int curr_cost, vector<vector<vector<int>>>&dp)
    {
        if(index>=n)
        {
            if(curr_cost==k)
            {
                // ans++;
                return 1;
            }
            return 0; 
        }
        int  result=0;
        if(dp[index][prev][curr_cost]!=-1)return dp[index][prev][curr_cost];
        for(int i=1;i<=m;i++)
        {
            if(i>prev && curr_cost>=k)
            {
                continue;

            }
            else if(i>prev)
            {
                result = (result + dfs(n,m,k,i,index+1,curr_cost+1,dp)) % MOD;
            }
            else
            {
                result = (result + dfs(n,m,k,prev,index+1,curr_cost,dp)) % MOD;
            }

        }
        
        dp[index][prev][curr_cost]=result;
        return result;


    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return dfs(n,m,k,0,0,0,dp);

    }
};