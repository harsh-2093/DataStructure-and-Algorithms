class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(nums[mid] == target) return true;

            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }

            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] > target){
                    high = mid-1;  // lett move
                }else{
                    low = mid+1;   // right move
                }

            }else{
               if(target > nums[mid] && target <= nums[high]){
                low = mid+1;  // right
               }else{
                 high = mid-1;
               }
            }
        }
        return 0;
    }
};