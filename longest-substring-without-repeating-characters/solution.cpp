class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,0);

        int l=0;
        int max_len=0;

        for(int r=0;r<s.size();r++)
        {
           

            if(mpp[s[r]]!=0)
            {
                while(s[l]!=s[r] && l<s.size())
                {
                     mpp[s[l]]=0;
                    l++;
                }
               
                l++;
            }
            mpp[s[r]]=1;
         max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};