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
        cout<<st.size();

        return st.empty();
    }
};