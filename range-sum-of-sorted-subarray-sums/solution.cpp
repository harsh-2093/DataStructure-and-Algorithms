class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;

        for(int i = 0; i < n; i++)
        {
            int curr = 0;

            for(int j = i; j < n; j++)
            {
                curr += nums[j];
                sums.push_back(curr);
            }
        }
        sort(sums.begin(),sums.end());
          int MOD = 1000000007;
        int ans=0;
        for(int i=left-1;i<right;i++)
        {
            ans=(ans+sums[i])%MOD;
        }
        return ans;
    }
};