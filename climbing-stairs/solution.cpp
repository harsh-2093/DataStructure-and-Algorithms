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
        vector<int>stair(n+1);
        stair[0]=0;
        stair[1]=1;
        stair[2]=2;

        for(int i=3;i<=n;i++)
        {
            stair[i]=stair[i-1]+stair[i-2];
        }
        return stair[n];
        // return ans;
    }
};