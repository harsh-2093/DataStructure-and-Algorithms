class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ')i++;
        int sign=1;
        long long result=0;
        if(i < s.size() && s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(i < s.size() && s[i]=='+')
        {
            sign=1;
            i++;
        }


        while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9)
        {
            int  digit=s[i]-'0';
            if(result>(INT_MAX-digit)/10)
            {
                if(sign==-1)
                {
                    return INT_MIN;

                }
                else
                {
                    return INT_MAX;
                }
            }
            result=result*10+digit;
            i++;
        }
        return result*sign;
    }
};