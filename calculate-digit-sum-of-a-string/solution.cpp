class Solution {
public:
    string digitSum(string s, int k) {
        
        while(s.size()>k)
        {
            string curr="";
            int sum=0;
            int l=0;
            for(int i=0;i<s.size();i++)
            {
                if(l==k-1)
                {
                    sum=sum+(s[i]-'0');
                    curr+=to_string(sum);
                    sum=0;
                    l=0;
                }
                else
                {
                   sum=sum+(s[i]-'0');
                    l++;
                }

            }
            if(l>0)
            curr+=to_string(sum);
            s=curr;
        }
        return s;
    }
};