class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string a,string b)
        {
            return a.size()<b.size();
        });
        vector<int>dp(words.size(),1);
        int ans=1;

        for(int l=0;l<words.size();l++)
        {
            for(int m=0;m<l;m++)
            {
                    bool flag=false;
                    const string& last=words[m];
                    const string& curr=words[l];
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
                        int take=dp[m]+1;
                        ans=max(ans,take);
                        dp[l]=max(dp[l],take);
                    }
            }
        }
        return ans;

    }
};