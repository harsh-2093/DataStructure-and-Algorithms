class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mpp;

        int max_len=INT_MIN;
        int l=0;
        for(int r=0;r<s.size();r++)
        {
            mpp[s[r]]++;

            while(mpp[s[r]]>2)
            {
                mpp[s[l]]--;
                l++;
            }
            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};