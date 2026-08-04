class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int start=INT_MAX;
        int end=INT_MIN;

        for(int d:nums)
        {
            start=min(start,d);
            end=max(end,d);
        }

        vector<int>mpp(end-start+1,0);

        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]-start]++;
        }

        vector<int>ans;
        for(int i=0;i<mpp.size();i++)
        {
            if(mpp[i]==0)
            {
                ans.push_back(i+start);
            }
        }
        return ans;
    }
};