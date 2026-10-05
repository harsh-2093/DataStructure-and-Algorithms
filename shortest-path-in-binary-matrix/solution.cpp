class Solution {
public:
    int cnt=1;
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>&q)
    {
        while(q.size()>0)
        {
            int n=q.size();

            for(int k=0;k<n;k++)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();

                vector<vector<int>>drxn{
                    {-1, -1},
                    {-1,  0},
                    {-1,  1},
                    { 0, -1},
                    { 0,  1},
                    { 1, -1},
                    { 1,  0},
                    { 1,  1}
                };
                for(auto a:drxn){
                    int x=a[0];
                    int y=a[1];
                    int size=grid.size()-1;

                    x=x+i;
                    y=y+j;

                    if(x<0 || y<0 || x>size || y>size||grid[x][y]==1)
                    {
                        continue;
                    }
                    else if(x==size && y==size)
                    {
                        return cnt+1;
                    }
                    else{
                        q.push({x,y});
                        grid[x][y]=1;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
        return -1;
        if(n==1)return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        return bfs(grid,q);
    }
};