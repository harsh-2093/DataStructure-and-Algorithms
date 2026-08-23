class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>indx_rmv;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty())
                {
                    indx_rmv.insert(i);
                }
                else
                {
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
           indx_rmv.insert(st.top());
           st.pop();
        }

        string ans="";

        for(int i=0;i<s.size();i++)
        {
            if(indx_rmv.find(i)==indx_rmv.end())
            {
                ans+=s[i];
            }
        }
        return ans;

    }
};