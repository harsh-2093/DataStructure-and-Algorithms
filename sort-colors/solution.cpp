class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end=nums.size()-1;
        int start=0;
        int mid=0;

        while(mid<=end)
        {
            if(nums[mid]==0)
            {
                
                swap(nums[start],nums[mid]);
                if(mid==start)mid++;
                start++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            
            else
            {
                swap(nums[end],nums[mid]);
                end--;
            }
        }
    }
};