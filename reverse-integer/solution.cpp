class Solution {
public:
    int reverse(int x) {
        long long num=0;
        while(x!=0)
        {
            int dig=x%10;
            num=num*10+dig;
            x/=10;
        }
        if (num > INT_MAX || num < INT_MIN)
                return 0; 
        return num;
        }
};