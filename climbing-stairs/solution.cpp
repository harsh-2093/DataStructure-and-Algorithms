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
        vector<int>stair(n+1,-1);
        return dfs(n,0,stair);
        // return ans;
    }
};