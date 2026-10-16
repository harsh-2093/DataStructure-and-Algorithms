class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid, vector<vector<int>>&dis)
    {
        while(q.size()>0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;

                q.pop();
                vector<vector<int>>drxn{
                    {0,1},
                    {0,-1},
                    {1,0},
                    {-1,0}
                };
                int m=grid.size()-1;
                for(auto a:drxn){
                    int i=a[0]+x;
                    int j=a[1]+y;

                    if(i<0 || j<0 || i>m || j>m|| grid[i][j]==1)
                    {
                        continue;
                    }

                    dis[i][j]=dis[x][y]+1;

                    q.push({i,j});
                    grid[i][j]=1;

                }

            }
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int no_land=0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis=grid;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {

                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j]=0;
                    no_land++;
                }
                else
                {
                    vis[i][j]=INT_MAX;
                }
                
            }
        }
        if(no_land==0 || no_land==grid.size()*grid.size())return -1;

        bfs(q,grid,vis);
        int maxi=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                maxi=max(maxi,vis[i][j]);
            }
        }
        return maxi;
    }
};