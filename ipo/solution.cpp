class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int>pq;
        vector<pair<int,int>>vec;
        //{capital,profitss}
        for(int i=0;i<capital.size();i++)
        {
            vec.push_back({capital[i],profits[i]});
        }

        sort(vec.begin(),vec.end());
        int i=0;
        while(k--)
        {
            while(i<capital.size() && vec[i].first<=w)
            {
                pq.push(vec[i].second);
                i++;
            }
            if(pq.empty())
            {
                break;
            }
            w+=pq.top();
            pq.pop();

        }
        return w;
    }
};