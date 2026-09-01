class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')')
            {
                string curr="";
                while(st.top()!='(')
                {
                    curr+=st.top();
                    st.pop();
                }
                st.pop();
                for(char e:curr)
                {
                    st.push(e);
                }
            }
            else
            {
                st.push(s[i]);
            }

        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};