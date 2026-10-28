class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        vector<int>mem(nums.size()+1,0);
        vector<int>mem2(nums.size()+1,0);
        int end=nums.size();

        // case1 //taking index 0
        int a=0;
        int b=nums[0];
        int c=max(b,nums[1]);
        for(int i=3;i<end;i++)
        {
            int steal=nums[i-1]+b;
            int leave=c;
            a=b;
            b=c;
            c=max(steal,leave);

        }

        //case2 ///leaving the index 0
        int a1=0;
        int b1=nums[1];
        int c1=max(b1,nums[2]);
        for(int i=3;i<end;i++)
        {
            int steal=nums[i]+b1;
            int leave=c1;
            a1=b1;
            b1=c1;
            c1=max(steal,leave);
        }

        return max(c,c1);
    }
};