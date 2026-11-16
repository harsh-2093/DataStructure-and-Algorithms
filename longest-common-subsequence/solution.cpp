class Solution {
public:
    //dp solution +memo
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        string ans="";
        for(int i=0;i<=text2.size();i++)dp[0][i]=0;
        for(int i=0;i<=text1.size();i++)dp[i][0]=0;

        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    int Equals=1+dp[i-1][j-1];
                    dp[i][j]=Equals;
                }
                else
                {
                    int left=dp[i][j-1];
                    int right=dp[i-1][j];
                    dp[i][j]=max(left,right);
                }
            }
        }
        int i=text1.size();
        int j=text2.size();

        while(i>0 && j>0)
        {
                if(text1[i-1]==text2[j-1])
                {
                    ans+=text1[i-1];
                    i--;
                    j--;
                }
                else
                {
                    int left=dp[i][j-1];
                    int right=dp[i-1][j];
                    if(left>right)
                    {
                        j--;
                    }
                    else
                    {
                        i--;
                    }
                }
        }
        reverse(ans.begin(),ans.end());
        cout<<ans;
        return dp[text1.size()][text2.size()];

    }
};