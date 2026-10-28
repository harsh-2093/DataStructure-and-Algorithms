class Solution {
public:

    void bfs(vector<vector<int>>& grid,vector<vector<int>>&visited,queue<pair<int,int>>&q)
    {
        int r=grid.size()-1;
        int c=grid[0].size()-1;

        while(q.size()>0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                vector<vector<int>>drxn{
                    {1,0},
                    {-1,0},
                    {0,1},
                    {0,-1}
                };

                for(auto a:drxn)
                {
                    int i=a[0]+x;
                    int j=a[1]+y;

                    if(i<0 || j<0 ||i>r || j>c||grid[i][j]==0)continue;
                    q.push({i,j});
                    grid[i][j]=0;

                }
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>>visited=grid;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1 &&(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1))
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]=0;
                    bfs(grid,visited,q);
                }
            }
        }
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};