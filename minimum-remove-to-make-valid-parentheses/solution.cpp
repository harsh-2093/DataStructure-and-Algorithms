class Solution {
public:
    string minRemoveToMakeValid(string s) {
        

        //for extra close bracket '('
        int open =0;
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                open++;
            }
            else if(s[i]==')')
            {
                if(open==0)
                {
                    continue;
                }
                else
                {
                    open--;
                }
            }
            ans+=s[i];

        }

        int close=0;
        string ans2="";
        for(int i=ans.size()-1;i>=0;i--)
        {
            if(ans[i]==')')
            {
                close++;
            }
            else if(ans[i]=='(')
            {
                if(close==0)
                {
                    continue;
                }
                else
                {
                    close--;
                }
            }
            ans2+=ans[i];

        }
        reverse(ans2.begin(),ans2.end());
        return ans2;
    }
};