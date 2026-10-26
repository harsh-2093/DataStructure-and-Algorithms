class Solution {
public:
    //bottom up approach in constant space complexity
    int fib(int n) {
        if(n<1)return 0;
        int a=0;
        int b=1;

        for(int i=2;i<n;i++)
        {
            int n=a+b;
            a=b;
            b=n;
        }

        return a+b;

    }
};