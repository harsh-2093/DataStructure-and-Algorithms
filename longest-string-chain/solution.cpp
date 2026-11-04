class Solution {
public:
    int dfs(vector<string>& words,int index,int prev,vector<vector<int>>&dp)
    {
        if(index>words.size()-1)
        {
            return 0;
        }

        if(prev==-1)
        {
            if(dp[index][prev+1]!=-1)return dp[index][prev+1];
            int take=1+dfs(words,index+1,index,dp);
            int skip=dfs(words,index+1,prev,dp);
            dp[index][prev+1]=max(take,skip);
            return max(take,skip);

        }
        else
        {
            bool flag=false;
            const string& last=words[prev];
            const string& curr=words[index];
            if(last.size()+1==curr.size())
            {
                
                int i=0;
                int j=0;
                int cnt=0;
                while(i<last.size()&&j<curr.size())
                {
                    if(last[i]==curr[j])
                    {
                        i++;
                        j++;
                    }
                    else
                    {
                        if(cnt==1)
                        {
                            break;
                        }
                        j++;
                        cnt++;
                    }
                }
                if(cnt<=1&& i==last.size())
                flag=true;
            
            }
            if(flag==true)
            {
                 if(dp[index][prev+1]!=-1)return dp[index][prev+1];
                int take=1+dfs(words,index+1,index,dp);
                int skip=dfs(words,index+1,prev,dp);
                 dp[index][prev+1]=max(take,skip);
                return max(take,skip);
            }
            else
            {
                if(dp[index][prev+1]!=-1)return dp[index][prev+1];
                int skip=dfs(words,index+1,prev,dp);
                 dp[index][prev+1]=skip;
                return skip;
            }
        }

    }
    int longestStrChain(vector<string>& words) {
        //sort acc to len
        sort(words.begin(),words.end(),[](string a,string b)
        {
            return a.size()<b.size();
        });
        vector<vector<int>>dp(words.size(),vector<int>(words.size()+1,-1));
        return dfs(words,0,-1,dp);
    }
};