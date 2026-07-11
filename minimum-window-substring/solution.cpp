class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>mpp(256,0);

        for(int i=0;i<t.size();i++)
        {
            mpp[t[i]]++;
        }

        string ans="";
        int min_len=INT_MAX;
        int count=0;
        int len=0;
        int left=0;

        int l=0;
        for(int i=0;i<s.size();i++)
        {
            if(mpp[s[i]]>0)
            {
                count++;
            }
            mpp[s[i]]--;

            while(count>=t.size())
            {
                 mpp[s[l]]++;
                if(i-l+1<min_len)
                {
                    min_len=i-l+1;
                    left=l;
                    len=i-l+1;
                }
                if(mpp[s[l]]>0)
                {
                    count--;
                }
               
                l++;

            }
        }
        return s.substr(left,len);
    }
};