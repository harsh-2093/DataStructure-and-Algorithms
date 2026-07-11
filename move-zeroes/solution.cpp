class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>arr;
        for(int d:nums)
        {
            if(d!=0)
            {
                arr.push_back(d);
            }
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=0;
        }
        for(int i=0;i<arr.size();i++)
        {
            nums[i]=arr[i];
        }

    }
};