class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>arr(nums.begin(),nums.end());
        int i=0;
        for(auto it:arr)
        {
            nums[i++]=it;
        }
        return arr.size();
    }
};