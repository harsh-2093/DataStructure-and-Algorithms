class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(n)
        {
            int prod_d=1;
            int temp=n;
            while(temp>0)
            {
                int dig=temp%10;
                prod_d*=dig;
                temp=temp/10;
            }
            if(prod_d%t==0)
            {
                return n;
            }
            n++;
        }
        return  -1;
    }
};