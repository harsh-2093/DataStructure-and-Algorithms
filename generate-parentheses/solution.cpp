class Solution {
public:
    int open=0;
    int close=0;
    void solve(string current,int n,vector<string>&result)
    {
        //bc
        if(current.size()==2*n)
        {
            result.push_back(current);
            return;
        }

        //explore1
        if(open>=close){
        if(open<n){
        current.push_back('(');
        open++;
        solve(current,n,result);
        current.pop_back();
        open--;
        }


        //explore2
        if(close<n){
        current.push_back(')');
        close++;
        solve(current,n,result);
        current.pop_back();
        close--;
        }
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve("",n,result);
        return result;
    }
};