class Solution {
public:
    int b_s(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        // int highlow=INT_MAX;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)
            {
                
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
    int searchInsert(vector<int>& nums, int target) {
        return b_s(nums,target);
    }
};