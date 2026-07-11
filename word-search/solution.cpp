class Solution {
public:
    bool result=false;
    void search(int row,int col,vector<vector<char>>& board, string& word,int index)
    {
        //base_case
        if(result)return;

        //1 result_case
        if(index==word.size())
        {
            result=true;
            return;
        }

        //2 return case
        if(row>=board.size() || col>=board[0].size() || board[row][col]=='$' ||row <0 ||col <0 || board[row][col]!=word[index] )
        {
            return;
        }


        //avoid redundancy
        char temp=board[row][col];
        board[row][col]='$';


        // //up,down,right,left
        // vector<vector<int>>drxn{
        //     {0,1},
        //     {0,-1},
        //     {1,0},
        //     {-1,0},
        // };



        // //explore
        // for(auto & d:drxn)
        // {
        //     int r1=row+d[0];
        //     int r2=col+d[1];

        //     search(r1,r2,board,word,index+1);
        // }
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++) {
            search(row + dr[i], col + dc[i], board, word, index + 1);
        }


        board[row][col]=temp;
        // index--;



    }
    bool exist(vector<vector<char>>& board, string word) {
        // row(n)|col(m)
        int n=board.size();
        int m=board[0].size();


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    search(i,j,board,word,0);
                }
            }
        }
        return result;




    }
};