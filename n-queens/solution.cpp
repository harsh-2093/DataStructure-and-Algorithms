class Solution {
public:
    vector<vector<string>>result;
    bool check(int row ,int col,vector<string>&board)
    {
        //check the top
        // if(col>=board.size() &&row ==board.size())return false;
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }

        //check the left_diognal
        int r=row;
        int c=col;
        while(r>=0 &&c>=0)
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
            r--;
            c--;
        }

        //check right_diognal
         r=row;
         c=col;
        while(r>=0 &&c<board.size())
        {
            if(board[r][c]=='Q')
            {
                return false;
            }
            r--;
            c++;

        }

        return true;
    }
    void solve(int row,vector<string>&board)
    {
        if(row ==board.size())
        {
            result.push_back(board);
            return;
        }

        for(int  i=0;i<board.size();i++)
        {
            if(check(row,i,board))
            {
                board[row][i]='Q';
                solve(row+1,board);
                board[row][i]='.';
                
            }

        }




    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        solve(0,board);
        return result;
    }
};