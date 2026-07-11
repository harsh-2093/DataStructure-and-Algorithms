class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;

        }
        unordered_map<char,char>mp;
        unordered_map<char,char>mp2;
        for(int i=0;i<s.size();i++)
        {
            char a= s[i];
            char b=t[i];
            if(!mp.empty() && mp.find(s[i])!=mp.end()&& mp[s[i]]!=t[i] ||
            !mp2.empty() && mp2.find(t[i])!=mp2.end()&& mp2[t[i]]!=s[i])
            {
                return false;
            }
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};