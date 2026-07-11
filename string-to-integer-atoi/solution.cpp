class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=+1;

        while(i<s.size()&&s[i]==' ')i++;
        if(s[i]=='-'){
            sign=-1;
            i++;
        }
        else if(s[i]=='+')i++;

        int result=0;
        while(i<s.size()&&s[i]>='0'&&s[i]<='9')
        {
            int digit=s[i]-'0';
            if(result>(INT_MAX-digit)/10){
                if(sign==-1)
                {
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
            }
            result=result*10+digit;
            i++;
            







            
        }
        cout<<sign;
        return result*sign;
        
        return 42;
    }
};