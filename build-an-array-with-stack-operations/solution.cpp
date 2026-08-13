class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>st;
        int i=1;
        int j=0;
        while(i<=n &&j<target.size())
        {
            st.push_back("Push");
            if(target[j]!=i)
            {
                st.push_back("Pop");
            }
            else
            {
                j++;
            }
            i++;

        }
        return st;
    }
};