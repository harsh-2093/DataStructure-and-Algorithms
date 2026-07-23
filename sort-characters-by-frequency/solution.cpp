class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        string temp="";
        for(char t:s)
        {
            mp[t]++;
        }
        vector<pair<char,int>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),[](auto &a,auto&b)
        {
            return a.second>b.second;
        });

        for(auto&p:vec)
        {
            while(p.second--)
            {
                temp+=p.first;
            }
        }

        return temp;
        
    }
};