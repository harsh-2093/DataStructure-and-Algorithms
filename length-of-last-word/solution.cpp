class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.size()-1;
        while(i>=0 &&s[i]==' ')i--;
        int cnt  =0;
        for(;i>=0;i--)
        {
            if(s[i]==' ')break;
            cnt++;
        }
        return cnt;
    }
};