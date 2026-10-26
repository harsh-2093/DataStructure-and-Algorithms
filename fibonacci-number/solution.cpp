class Solution {
public:
    int dfs(int n)
    {
        if(n==0)return 0;
        if(n==1) return 1;

        return dfs(n-1)+dfs(n-2);
    }
    int fib(int n) {
        return dfs(n);
    }
};