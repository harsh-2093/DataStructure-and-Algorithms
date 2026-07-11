class Solution {
public:
    int strStr(string haystack, string needle) {
        int left=0;
        int right=needle.size()-1;

        while(right<haystack.size())
        {
            string val="";
            for(int i=left;i<=right;i++)
            {
                val+=haystack[i];
            }
            if(val==needle)
            {
                return left;
            }
            right++;
            left++;
        }
        return -1;
    }
};