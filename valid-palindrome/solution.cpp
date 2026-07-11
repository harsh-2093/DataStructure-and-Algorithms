class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>st;

        for(int i=0;i<s.size();i++)
        {
            if((int)s[i]<=122 &&(int)s[i]>=97|| (int)s[i]<=90 &&(int)s[i]>=65||(int)s[i]<=57 &&(int)s[i]>=48)
            {
                st.push_back(tolower(s[i]));
            }
        }


        int i=0;
        int j=st.size()-1;
        for(char d:st)
        {
            cout<<d;
        }

        while(i<j)
        {
            if(st[i++]!=st[j--])
            {
                return false;
            }
        }

        return true;
        


    }
};