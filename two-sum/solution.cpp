class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++)
        {
            int value=target-nums[i];

            if(mpp.find(value)!=mpp.end())
            {
                result.push_back(i);
                result.push_back(mpp[value]);
                return result;
            }
                mpp.insert({nums[i],i});
            


        }
        return result;
    }
};