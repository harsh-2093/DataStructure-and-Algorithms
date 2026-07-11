class Solution {
public: 
    vector<string>result;
    void solve(int index,string digit,unordered_map<char,string>&mpp,string temp)
    {
        if(temp.size()==digit.size())
        {
            result.push_back(temp);
            return;
        }
        // if(index>=digit.size())
        // {
        //     return;
        // }

        for(char c:mpp[digit[index]])
        {
            temp.push_back(c);
            solve(index+1,digit,mpp,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp
        {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };

        solve(0,digits,mpp,"");
        return result;

        
    }
};