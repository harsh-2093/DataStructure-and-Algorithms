class Solution {
public:
    int dfs(string &s1,string &s2,int i,int j, vector<vector<int>>&dp)
    {
        if(i>=s1.size() || j>=s2.size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])
        {
            int Equals=1+dfs(s1,s2,i+1,j+1,dp);
            dp[i][j]=Equals;
            return Equals;
        }
        else
        {
            int left=dfs(s1,s2,i,j+1,dp);
            int right=dfs(s1,s2,i+1,j,dp);
            dp[i][j]=max(left,right);
            return max(left,right);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return dfs(text1,text2,0,0,dp);
    }
};