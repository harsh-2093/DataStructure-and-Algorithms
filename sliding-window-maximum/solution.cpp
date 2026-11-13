class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        //value,index
        vector<int>ans;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            pq.push({nums[r],r});

            while(r-l+1>k)
            {
                l++;
            }
            if(r-l+1==k)
            {
                while(pq.top().second<l)
                {
                    pq.pop();
                }
                
            
                ans.push_back(pq.top().first);
                
            }
        }
        return ans;
    }
};