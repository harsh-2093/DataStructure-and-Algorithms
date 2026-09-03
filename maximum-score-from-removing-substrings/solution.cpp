class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        int score=0;

        if(x>y)
        {
            //ab
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='b')
                {
                    if(!st.empty() &&st.top()=='a')
                    {
                        score+=x;
                        st.pop();
                        continue;
                    }
                }

                st.push(s[i]);
            }
            string curr="";
            while(!st.empty())
            {
                curr+=st.top();
                st.pop();
            }
            reverse(curr.begin(),curr.end());
            for(int i=0;i<curr.size();i++)
            {
                if(curr[i]=='a')
                {
                    if(!st.empty() &&st.top()=='b')
                    {
                        score+=y;
                        st.pop();
                        continue;
                    }
                }

                st.push(curr[i]);
            }
        }
        else
        {
             //ba
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='a')
                {
                    if(!st.empty() &&st.top()=='b')
                    {
                        score+=y;
                        st.pop();
                        continue;
                    }
                }

                st.push(s[i]);
            }
            string curr="";
            while(!st.empty())
            {
                curr+=st.top();
                st.pop();
            }
            reverse(curr.begin(),curr.end());
            for(int i=0;i<curr.size();i++)
            {
                if(curr[i]=='b')
                {
                    if(!st.empty() &&st.top()=='a')
                    {
                        score+=x;
                        st.pop();
                        continue;
                    }
                }

                st.push(curr[i]);
            }
        }
        return score;

    }
};