class Solution {
public:
    int dfs(vector<int>& nums,int start,int end, vector<int>&mem)
    {
        if(start>end)return 0;

        if(mem[start]!=-1)return mem[start];

        int steal=nums[start]+dfs(nums,start+2,end,mem);
        int leave=dfs(nums,start+1,end,mem);

        mem[start]=max(steal,leave);
        return max(steal,leave);


    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int max_money=INT_MIN;
        // case1
        vector<int>mem(nums.size(),-1);
        vector<int>mem2(nums.size(),-1);
        //case2
    int           end=nums.size()-1;
        max_money=max(max_money,dfs(nums,0,end-1,mem));

        max_money=max(max_money,dfs(nums,1,end,mem2));
        return max_money;
    }
};