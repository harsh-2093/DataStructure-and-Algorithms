class Solution {
public:
    int calculate(string s) {
        stack<int>st;

        long long number=0;
        int result=0;
        int sign=1;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                result=result+(number*sign);
                st.push(result);
                st.push(sign);
                number=0;
                result=0;
                sign=1;
            }
            else if(s[i]==')')
            {
                result=result+(number*sign);
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
                number=0;
                sign=1;
            }
           else if(s[i]>='0' && s[i]<='9')
            {
                int digit=s[i]-'0';
                number=number*10+digit;
            }
            else if(s[i]=='+')
            {
                result=result+(number*sign);
                number=0;
                sign=1;
            }
            else  if(s[i]=='-')
            {
                result=result+(number*sign);
                number=0;
                sign=-1;
            }
        }

        result=result+(number*sign);
        return result;


    }
};