class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int end=INT_MAX;
        int ans=-1;
        unordered_set<int>nms;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=0)continue;
            end=max(end,nums[i]);
            nms.insert(nums[i]);

        }

        for(int i=1;i<=end;i++)
        {
            if(nms.find(i)==nms.end())
            {
                ans=i;
                break;
            }

        }
        if(ans==-1)
        {
            return end+1;
        }
        return ans;

    }
};