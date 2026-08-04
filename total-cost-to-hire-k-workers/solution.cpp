class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i=0;
        int j=costs.size()-1;

        priority_queue<int,vector<int>,greater<int>>lft_pq;
        priority_queue<int,vector<int>,greater<int>>rgt_pq;


        while(lft_pq.size()<candidates  && i<=j)
        {
            lft_pq.push(costs[i]);
            i++;
        }
        while( rgt_pq.size()<candidates && i<=j)
        {
            rgt_pq.push(costs[j]);
            j--;
        }

        long long cost=0;

        while(!lft_pq.empty() && !rgt_pq.empty() && k>0)
        {
            if(lft_pq.top()<=rgt_pq.top())
            {
                cost+=lft_pq.top();
                k--;
                lft_pq.pop();
                if(i<=j)
                {
                    lft_pq.push(costs[i++]);
                }
            }
            else
            {
                cost+=rgt_pq.top();
                k--;
                rgt_pq.pop();
                if(i<=j)
                {
                    rgt_pq.push(costs[j--]);
                }
            }
        }

        while(!lft_pq.empty() && k>0)
        {
            cost+=lft_pq.top();
            k--;
            lft_pq.pop();
            if(i<=j)
            {
            lft_pq.push(costs[i++]);
            }
        }
        while(!rgt_pq.empty() && k>0)
        {
            cost+=rgt_pq.top();
                k--;
                rgt_pq.pop();
                if(i<=j)
                {
                    rgt_pq.push(costs[j--]);
                }
        }
        return cost;
    }
};