class Solution {
public:
    string frequencySort(string s) {
        vector<int>mpp(128);

        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;

        for(int i=0;i<127;i++)
        {
            char c=i;
            int  v=mpp[i];
            if(v!=0)
            {
                pq.push({v,c});
            }
            
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