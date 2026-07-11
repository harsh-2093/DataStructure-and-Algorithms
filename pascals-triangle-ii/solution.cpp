class Solution {
public:
     
    int num(int n,int r)
    {
        long long numer=1;
        for(int i=0;i<r;i++)
        {
            numer*=n-i;
            numer/=i+1;
        }
        return numer;
    }
    vector<int> getRow(int rowIndex) {
        int n=rowIndex+1;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
        {
            arr[i]=(int)num(n-1,i);
        }
        return arr;
    }
};