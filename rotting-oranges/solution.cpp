class Solution {
public:

    void dfs(queue<pair<int,int>>&q, vector<vector<int>>&dis,vector<vector<int>>& grid)
    {
        while(q.size()>0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                grid[x][y]=0; 

                vector<vector<int>>drxn{
                    {0,1},
                    {0,-1},
                    {1,0},
                    {-1,0}
                };
                int n=grid.size()-1;
                int m=grid[0].size()-1;
                for(auto a:drxn)
                {
                    int i=a[0];
                    int j=a[1];

                    if(x+i<0 || y+j<0 || x+i>n || y+j>m || grid[x+i][y+j]!=1)continue;

                    q.push({x+i,y+j});
                    grid[x+i][y+j]=0;
                    dis[x+i][y+j]=dis[x][y]+1;

                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        vector<vector<int>>vis=grid;

        //initial nodes to start multi source bfs
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=0;
                }
                else if(grid[i][j]==1)
                {
                    vis[i][j]=INT_MAX;
                }
                else
                {
                     vis[i][j]=0;
                }
            }
        }
        dfs(q,vis,grid);
        int min_time=0;

        //checking for unreachable orange
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)return -1;
                min_time=max(min_time,vis[i][j]);
            }
        }
        return min_time;

    }
};