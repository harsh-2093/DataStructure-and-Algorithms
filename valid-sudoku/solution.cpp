class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>mp;
        for(int  i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                string temp1="muje"+string(1,board[i][j])+"mila"+to_string(i);
                
                string temp2="muje fir"+string(1,board[i][j])+"mila"+to_string(j);
                string temp3="muje"+string(1,board[i][j])+"mila"+to_string(i/3)+to_string(j/3);

                if
                (
                    mp.find(temp1)!=mp.end() ||
                    mp.find(temp2)!=mp.end() ||
                    mp.find(temp3)!=mp.end()   
                               )
                {
                    return false;
                }
                mp.insert(temp1);
                mp.insert(temp2);
                mp.insert(temp3);
            }
        }
        return true;
    }
};