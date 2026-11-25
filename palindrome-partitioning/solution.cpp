class Solution {
public:
    vector<vector<string>>ans;
    void dfs(int index,vector<string>&result,vector<vector<bool>>&dp,string &s)
    {
        if(index>=s.size())
        {
            ans.push_back(result);
            return;

        }

        for(int i=index;i<s.size();i++)
        {
            if(dp[index][i]==true)
            {
                result.push_back(s.substr(index,i-index+1));
                dfs(i+1,result,dp,s);
                result.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        //state defn:dp[i][j]= true ie s[i:j] is palindrome
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));

        //marking the s with len 1 true
        for(int i=0;i<s.size();i++)
        {
            dp[i][i]=true;
        }

        //start to fill the dp top to down 
        for(int l=2;l<=s.size();l++)// l: len of substr
        {
            for(int i=0;i+l-1<s.size();i++)// i: start index 
            {
                int j=i+l-1; //j:end index

                if(s[i]==s[j])
                {
                    if(l==2)
                    dp[i][j]=true;
                    else
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                }

            }
        }

        //
        vector<string>result;
        dfs(0,result,dp,s);
        return ans;

    }
};