class Solution {
public:
    vector<string>result;
    void solve(int index,string s,unordered_set<string>&dict,string temp)
    {

        //Base Case
        if(index>=s.size())
        {
            string ans = temp;     // make a copy
            if(!ans.empty()) ans.pop_back();
            result.push_back(ans);
            return;
        }

        //for exploration
        string word="";
        for(int i=index;i<s.size();i++)
        {
            word.push_back(s[i]);
            if(dict.find(word)!=dict.end())
            {
                string prev=temp;
                 temp+=word;
                 temp+=" ";
                solve(i+1,s,dict,temp);
                temp=prev;

            }
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        string temp;
        solve(0,s,dict,temp);
        return result;

    }
};