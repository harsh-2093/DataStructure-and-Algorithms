class Solution {
public:
    int minChanges(string s) {
        
        int ans=0;
        int count=0;
        int curr=-1;
        for(int i=0;i<s.size();i++)
        {
            if(count==0 || s[i]==s[curr])
            {
                curr=i;
                count++;
            }
            else if(count%2==0)
            {
                curr=i;
                count=0;
                count++;
            }
            else
            {
                ans++;
                count=0;

            }
        }
        return ans;
    }
};