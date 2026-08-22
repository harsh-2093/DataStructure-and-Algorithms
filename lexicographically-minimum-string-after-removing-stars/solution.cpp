class Solution {
public:
class comp{
    public:
    bool operator()(pair<char,int>a,pair<char,int>b)
    {
        if(a.first!=b.first)
        {
            return a.first>b.first;
        }
        return a.second<b.second;
    }
};
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='*')
            {
                pq.pop();
            }
            else
            {
                pq.push({s[i],i});
            }
           
        }
        vector<pair<char,int>>arr;

        while(!pq.empty())
        {
            char c=pq.top().first;
            int idx=pq.top().second;
            pq.pop();
            arr.push_back({c,idx});
        }

        sort(arr.begin(),arr.end(),[](pair<char,int>a,pair<char,int>b){
            return a.second<b.second;
        });

        string ans="";


        for(int i=0;i<arr.size();i++)
        {
            ans+=arr[i].first;
        }
        return ans;

    }
};