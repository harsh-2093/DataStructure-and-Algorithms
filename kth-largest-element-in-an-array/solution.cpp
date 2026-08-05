class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(int d :nums)
        {
            if(pq.size()<k)
            {
                pq.push(d);
            }
            else
            {
                if(pq.top()<d)
                {
                    pq.pop();
                    pq.push(d);
                }
            }
        }

        return pq.top();
    }
};