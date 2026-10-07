class Solution {
public:
    int start_i=-1;
    int start_j=-1;
    int cnt=0;

    int bfs(vector<vector<char>>& maze,queue<pair<int,int>>&q){

        while(q.size()>0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                int n=maze.size()-1;
                int m=maze[0].size()-1;

                if(x<0 || y<0 ||x>n ||y>m || maze[x][y]=='+')
                {
                    continue;
                }
                if((x==0 || y==0 ||x==n ||y==m)&& !(x==start_i && y==start_j))
                {
                    return cnt;
                }
                maze[x][y]='+';

                vector<vector<int>>drxn{
                    {1,0},
                    {-1,0},
                    {0,1},
                    {0,-1}
                };

                for(auto a:drxn){
                    int i=a[0];
                    int j=a[1];
                    q.push({x+i,y+j});
                }

            }
            cnt++;
        }
        return -1;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        start_i=entrance[0];
        start_j=entrance[1];

        queue<pair<int,int>>q;
        q.push({start_i,start_j});

        return bfs(maze,q);

    }
};