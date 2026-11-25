class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        //state defn:dp[i][j] ==true means s[i:j],inclusive i,j is palindrome

        int longest=0;
        string ans="";
        for(int l=1;l<=n;l++)//l=len of substr
        {
            for(int i=0;i+l-1<n;i++)//i+l-1=j end index of substr of len l && i is  the start index 
            {
                int j=i+l-1;

                //len=1 ie. i==j 
                if(i==j)
                {
                    dp[i][j]=true;
                }
                //len =2 ie i+1==j 
                else if(i+1==j)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                    }
                }
                //len>2 1. check s[i] equals s[j] then check s[i+1] equals s[j-1] from stored dp
                else
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                    {
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]==true && j-i+1>longest)
                {
                    longest=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};