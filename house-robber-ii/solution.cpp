class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>mem(nums.size()+1,0);
        vector<int>mem2(nums.size()+1,0);
        int end=nums.size();

        // case1 //taking index 0
        mem[0]=0;
        mem[1]=nums[0];
        mem[2]=max(mem[1],nums[1]);
        for(int i=3;i<end;i++)
        {
            int steal=nums[i-1]+mem[i-2];
            int leave=mem[i-1];
            mem[i]=max(steal,leave);
        }

        //case2 ///leaving the index 0
        mem2[0]=0;
        mem2[1]=nums[1];
        mem2[2]=max(mem2[1],nums[2]);
        for(int i=3;i<end;i++)
        {
            int steal=nums[i]+mem2[i-2];
            int leave=mem2[i-1];
            mem2[i]=max(steal,leave);
        }

        return max(mem[end-1],mem2[end-1]);
    }
};