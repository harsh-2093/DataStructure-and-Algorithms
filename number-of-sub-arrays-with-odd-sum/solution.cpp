class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod=1e9+7;
        vector<int>prefixSum;
        int sum=0;
        for(int a:arr)
        {
            sum+=a;
            prefixSum.push_back(sum);
        }
        int oddCount=0;
        int evenCount=1;
        int ans=0;

        for(int i=0;i<prefixSum.size();i++)
        {
            if(prefixSum[i]%2==0)
            {
                ans=(ans+oddCount)%mod;
                evenCount++;
            }
            else
            {
                ans=(ans+evenCount)%mod;
                oddCount++;
            }
        }
        return ans;
    }
};