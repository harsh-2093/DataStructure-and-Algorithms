class Solution {
public: 
    void bfs(  queue<pair<int,int>>&q,vector<vector<int>>&visited,vector<vector<char>>& board)
    {
        int n=board.size()-1;
        int m=board[0].size()-1;

        while(q.size()>0)
        {
            int l=q.size();

            for(int i=0;i<l;i++)
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
                    int i=a[0];
                    int j=a[1];

                    if(x+i<0 || y+j<0 || x+i>n || y+j>m || board[x+i][y+j]=='.' || visited[x+i][y+j]==1)continue;
                    visited[x+i][y+j]=1;
                    q.push({x+i,y+j});

                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int cnt=0;
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='X' && visited[i][j]==0)
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j]=1;
                    bfs(q,visited,board);
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};