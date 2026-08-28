class Solution {
public:
bool isValid(string s) {
        unordered_map<char,char>mpp{
            {'(',')'},
            {'{','}'},
            {'[',']'},
        };
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                if(mpp.find(s[i])==mpp.end())
                {
                    return false;
                }
                st.push(s[i]);
            }
            else{
            char back=st.top();
            if(mpp[back]==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
            }
        }

        return st.empty();
    }
    vector<string>ans;
    void solve(string curr,int n,int open,int close)
    {
        if(curr.size()==2*n)
        {
            if( open==close)
            {
                ans.push_back(curr);

            }
            return;

        }


        curr.push_back('(');
        solve(curr,n,open+1,close);
        curr.pop_back();

        if(close<open){
        curr.push_back(')');
        solve(curr,n,open,close+1);
        }
        // curr.pop_back();

    }
    vector<string> generateParenthesis(int n) {
        solve("",n,0,0);
        return ans;
    }
};