class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>arr;
        deque<int>ms;

        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            if(ms.empty() || nums[ms.back()] >=nums[r])
            {
                ms.push_back(r);
            }
            else
            {
                while(!ms.empty() && nums[ms.back()] <nums[r])
                {
                    ms.pop_back();
                }
                ms.push_back(r);
            }

            while(r-l+1>k)
            {
                if(nums[l]==nums[ms.front()]){
                ms.pop_front();
                }
                l++;
            }
            if(r-l+1==k)
            {
                arr.push_back(nums[ms.front()]);
            }
        }
        return arr;

    }
};