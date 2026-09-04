class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size()-1;
        vector<int>p_max;
        vector<int>p_min(nums.size());
        int M=nums[0];
        int m=nums[n];

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>M)
            {
                M=nums[i];
            }
            p_max.push_back(M);
        }
        for(int i=n;i>=0;i--)
        {
            if(nums[i]<m)
            {

                m=nums[i];
            }
            p_min[i]=m;
        }
        int ans=-1;

        for(int i=0;i<nums.size();i++)
        {
            if((p_max[i]-p_min[i])<=k)
            {
                return i;
            }
        }

        return ans;
        
    }
};