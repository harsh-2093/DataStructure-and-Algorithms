class Solution {
public:
    int cnt=0;
    int bfs(vector<vector<char>>& grid,queue<pair<int,int>>&q)
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
                    {-1, 0},  // up
                    {1, 0},   // down
                    {0, -1},  // left
                    {0, 1}    // right
                };
                for(auto a:drxn){
                    int x=a[0];
                    int y=a[1];
                    int m=grid.size()-1;
                    int n=grid[0].size()-1;

                    x=x+i;
                    y=y+j;

                    if(x<0 || y<0 || x>m || y>n||grid[x][y]=='0')
                    {
                        continue;
                    }
                    else{
                        q.push({x,y});
                        grid[x][y]='0';
                    }
                }
            }
        }
        return -1;
    }
    int numIslands(vector<vector<char>>& grid) {
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'){
                queue<pair<int,int>>q;
                q.push({i,j});
                grid[i][j]='0';
                bfs(grid,q);
                cnt++;
                }
            }
        }
        return cnt;
    }
};