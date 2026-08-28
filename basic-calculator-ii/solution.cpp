class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        char sign='+';
        int num=0;
        for(int i = 0; i <= s.size(); i++)
        {
            // 1. Build number
            if(i < s.size() && isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }

            // 2. When operator/end is reached
            if(i == s.size() || s[i] == '+' || s[i] == '-' ||
            s[i] == '*' || s[i] == '/')
            {
                // use previous sign with num
                if(sign=='+')
                {
                    st.push(num*1);
                    sign=s[i];
                    num=0;
                }
                else if(sign=='-')
                {
                    st.push(num*-1);
                    sign=s[i];
                    num=0;
                }
                else if(sign=='*')
                {
                    int val=st.top();
                    st.pop();

                    st.push(val*num);
                    sign=s[i];
                    num=0;
                }
                else if(sign=='/')
                {
                    int val=st.top();
                    st.pop();
                    st.push(val/num);
                    sign=s[i];
                    num=0;
                }
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};