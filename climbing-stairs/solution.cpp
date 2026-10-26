class Solution {
public:
    int  dfs(int n,int start,vector<int>&stair)
    {
        if(start>n)return 0;
        if(start==n)
        {
            return 1;
        }
        if(stair[start]!=-1)return stair[start]; 
        int left=dfs(n,start+1,stair);
        int right=dfs(n,start+2,stair);

        return stair[start] =left+right;
    }
    int climbStairs(int n) {
        if(n<=2)return n;
        int a=1;
        int b=2;
        int c=3;

        for(int i=3;i<=n;i++)
        {
            c=b+a;
            a=b;
            b=c;

        }
        return c;
        // return ans;
    }
};