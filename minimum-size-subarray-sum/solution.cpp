class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len=INT_MAX;
        int sum=0;

        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            sum+=nums[r];

            while(sum>=target)
            {
                min_len=min(min_len,(r-l+1));
                sum-=nums[l];
                l++;
            }
            // if(sum==target)
            // {
            //     min_len=min(min_len,(r-l+1));
            // }

        }
        if(min_len==INT_MAX)return 0;
        return min_len;
    }
};