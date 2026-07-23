class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;

        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;

        for(auto it =mpp.begin();it!=mpp.end();++it)
        {
            char c=it->first;
            int  v=it->second;
            pq.push({v,c});
        }
        string ans="";

        while(!pq.empty())
        {
            int v=pq.top().first;
            while(v--)
            {
                ans+=pq.top().second;
            }
            pq.pop();
        }
        return ans;
    }
};