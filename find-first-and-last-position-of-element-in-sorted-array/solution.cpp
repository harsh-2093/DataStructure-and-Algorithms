class Solution {
public:
    // vector<int>result{3};
    int last_occur(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return res;
    }
    int first_occur(vector<int>& nums, int target)
    {
        int low=0;
        int high=nums.size()-1;
        int res=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int val=first_occur(nums,target);
        // cout<<val;
        int val2=last_occur(nums,target);
        // cout<<val2;
        return {val,val2};
    }
};