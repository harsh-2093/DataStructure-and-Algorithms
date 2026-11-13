class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;

        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            if(dq.empty()||nums[dq.back()]>=nums[r])
            {
                dq.push_back(r);
            }
            else
            {
                while(!dq.empty() && nums[dq.back()]<nums[r])
                {
                    dq.pop_back();
                }
                dq.push_back(r);
            }
            while(r-l+1>k)
            {
                if(l==dq.front())
                {
                    dq.pop_front();
                }
                l++;
            }
            if(r-l+1==k)
            {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};