class Solution {
public:
    void bfs(queue<pair<int,int>>&q,vector<vector<char>>& board)
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
                    {1,0},
                    {-1,0},
                    {0,1},
                    {0,-1}
                };

                for(auto a:drxn)
                {
                    int i=a[0]+x;
                    int j=a[1]+y;

                    if(i<0||j<0|| i>board.size()-1 || j>board[0].size()-1 ||board[i][j]!='O')continue;

                    q.push({i,j});
                    board[i][j]='#';
                }

            }
        }
    }
    void solve(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O'&&( i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1))
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    board[i][j]='#';
                    bfs(q,board);
                }
            }
        }
        //
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }                
            }
            
        }
    }
};