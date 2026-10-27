class Solution {
public:
    //bootom up approach
    int rob(vector<int>& nums) {
        vector<int>mem(101,0);
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        int max_money=INT_MIN;
        mem[0]=0;
        mem[1]=nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            int steal=nums[i-1]+mem[i-2];
            int skip=mem[i-1];
            mem[i]=max(steal,skip);
            max_money=max(steal,skip);
        }
        return max_money;
    }
};