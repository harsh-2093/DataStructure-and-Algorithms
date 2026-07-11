class Solution {
public:
double Power(double x, int n)
{
    if(n==0)
        {
            return 1;
        }

        double ans=Power(x,n/2);

        if(n%2==0)
        {
            return ans*ans;
        }
        else{
            return x*ans*ans;
        }
}
    double myPow(double x, int n) {
        long long N=n;
        if(N<0)
        {
            x=1.0/x;
            N=-N;
        }
        return Power(x,N);
    }
};