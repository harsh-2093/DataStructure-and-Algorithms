class Solution {
public:
    //bottom up approach
    int fib(int n) {
        if(n<1)return 0;
        vector<int>vis(n+1,-1);
        vis[0]=0;
        vis[1]=1;

        for(int i=2;i<=n;i++)
        {
            vis[i]=vis[i-1]+vis[i-2];
        }
        return vis[n];

    }
};