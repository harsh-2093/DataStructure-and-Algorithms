class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        bool ans=false;
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            mpp[nums[r]]++;
            if(mpp[nums[r]]>1 && r-l<=k)
                {
                    ans=true;
                    break;
                }

            if((r-l)>=k)
            {
                // if(mpp[nums[l]]>1)
                // {
                //     ans=true;
                //     break;
                // }
                mpp[nums[l]]--;
                l++;
            }

        }
        return ans;

    }
};