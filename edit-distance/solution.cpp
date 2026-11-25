class Solution {
public:
    int dfs(string &word1, string &word2,int i,int j, vector<vector<int>>&dp)
    {
        if(j<0)
        {
            return i+1;
        }
        if(i<0)
        {
            return j+1;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j])
        {
            return dp[i][j]=dfs(word1,word2,i-1,j-1,dp);
        }
        else
        {

            int insert=1+dfs(word1,word2,i,j-1,dp);
            int dlt=1+dfs(word1,word2,i-1,j,dp);
            int repl=1+dfs(word1,word2,i-1,j-1,dp);
            return dp[i][j]=min(insert,min(dlt,repl));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        int n=word1.size();
        int m=word2.size();
        for(int i=0;i<=n;i++)dp[i][0]=i;
        for(int j=0;j<=m;j++)dp[0][j]=j;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    int insert=1+dp[i][j-1];
                    int dlt=1+dp[i-1][j];
                    int repl=1+dp[i-1][j-1];
                    dp[i][j]=min(insert,min(dlt,repl));
                }
            }
        }
        return dp[n][m];

    }
};