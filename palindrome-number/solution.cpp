class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        int n=x;
        long long digit=0;
        while(n!=0)
        {
            int num=n%10;
            digit=num+(digit*10);
            n=n/10;
        }
        if(digit==x)return true;
        return false;
        
    }
};