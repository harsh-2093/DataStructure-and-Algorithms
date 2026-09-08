class Solution {
public:
    int countCommas(int n) {
        if(n<=999)return 0;
        int org=n;
        int no=n-999;
        int cnt=0;
        while(n>0)
        {
            cnt++;
            n=n/10;

        }
        cout<<cnt<<endl;
        cout<<no<<endl;
        int comma=0;
        if(org>=1 &&org<=999) comma =0;
        else if(org>=1000 && org<=999999)comma=1;
        else{
            comma=2;
        }
        cout<<comma;
        return comma*no;
    }
};