class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int ans=0;

        for(int d:piles)
        {
            pq.push(d);
            ans+=d;
        }
        
        while(k--)
        {
            int val=pq.top();
            ans-=val;
            val=val-floor(val/2);
            pq.pop();
            pq.push(val);
            ans+=val;
        }
        return ans;
    }
};