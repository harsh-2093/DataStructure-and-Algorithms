class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int mid=n/2;
        string  ans="";

        if(n%2==0)
        {
            sort(s.begin(),s.begin()+mid);
            for(int i=0;i<mid;i++)
            {
                ans+=s[i];
            }
            reverse(s.begin(),s.begin()+mid);
            for(int i=0;i<mid;i++)
            {
                ans+=s[i];
            }
            return ans;
        }
        else
        {
            if(n==1)return s;
            char ch=s[mid];
            sort(s.begin(),s.begin()+mid);
            for(int i=0;i<mid;i++)
            {
                ans+=s[i];
            }
            ans+=ch;
            reverse(s.begin(),s.begin()+mid);
            for(int i=0;i<mid;i++)
            {
                ans+=s[i];
            }
            return ans;


        }
        return " ";
    }
};