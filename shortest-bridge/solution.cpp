class Solution {
public:
    queue<pair<int,int>>f_q;

    void dfs(vector<vector<int>>&grid,queue<pair<int,int>>q,int i,int j)
    {
        q.push({i,j});
        grid[i][j] = 0;

        while(q.size()>0)
        {
            int n=q.size();

            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                f_q.push({x,y});

                int n=grid.size()-1;
                int m=grid[0].size()-1;

                vector<vector<int>>drxn{
                    {1,0},
                    {-1,0},
                    {0,1},
                    {0,-1}
                };

                for(auto a:drxn)
                {
                    int k=x+a[0];
                    int c=y+a[1];

                    if(k<0 || c<0 || k>n ||c>m || grid[k][c]==0)
                    {
                        continue;
                    }
                    q.push({k,c});
                    grid[k][c] = 0;

                }
            }
        }
    }
    int cnt=0;
    int f_dfs(vector<vector<int>>&grid)
    {

        while(f_q.size()>0)
        {
            int n=f_q.size();

            for(int i=0;i<n;i++)
            {
                int x=f_q.front().first;
                int y=f_q.front().second;
                f_q.pop();
                

                int n=grid.size()-1;
                int m=grid[0].size()-1;

                vector<vector<int>>drxn{
                    {1,0},
                    {-1,0},
                    {0,1},
                    {0,-1}
                };

                for(auto a:drxn)
                {
                    int k=x+a[0];
                    int c=y+a[1];

                    if(k<0 || c<0 || k>n ||c>m || grid[k][c]==-1)
                    {
                        continue;
                    }
                    if(grid[k][c]==1)
                    {
                        return cnt;
                    }
                    f_q.push({k,c});
                    grid[k][c]=-1;

                }
             
            }
            cnt++;
               
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;

        bool found=false;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,q,i,j);
                    found=true;
                    break;
                }
                
            }
            if(found==true)break;
        }
        return f_dfs(grid);
    }
};