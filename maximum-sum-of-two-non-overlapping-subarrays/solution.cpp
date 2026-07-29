class Solution {
public:
    int solve(vector<int>& nums, int firstLen, int secondLen,vector<int>&pf)
    {
        int k=firstLen+secondLen-1;
        int l=0;

        int l_max=INT_MIN;
        int r_max=INT_MIN;

        int sum=INT_MIN;

        for(int r=k;r<nums.size();r++)
        {
            int start=r-(secondLen-1);
            int r_sum=pf[r]-(start==0?0:pf[start-1]);

            int leftEnd = r - secondLen;
            int leftStart = leftEnd - firstLen + 1;
            
            int l_sum=pf[leftEnd]-(leftStart == 0 ? 0 : pf[leftStart-1]);

            l_max=max(l_max,l_sum);
            
            sum=max(sum,r_sum+l_max);


            if(r-l>k)
            {
                l++;
            }
           

        }
        return sum;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        vector<int>pf;

        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            pf.push_back(ans);
        }

        int answ=solve(nums,firstLen,secondLen,pf);
        answ=max(answ,solve(nums,secondLen,firstLen,pf));
        return answ;



    }
};