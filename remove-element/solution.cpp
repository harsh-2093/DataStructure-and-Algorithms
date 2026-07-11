class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                arr.push_back(nums[i]);
            }

        }
        int i=0;
        for(int d:arr)
        {
            nums[i++]=d;
        }
        return arr.size();
    }
};