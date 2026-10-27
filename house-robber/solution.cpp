class Solution {
public:
    int  dfs(vector<int>& nums,int index, vector<int>&mem)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(mem[index]!=-1)return mem[index];

        int steal=nums[index]+dfs(nums,index+2,mem);
        int skip=dfs(nums,index+1,mem);

        return mem[index]=max(steal,skip);

    }
    int rob(vector<int>& nums) {
        vector<int>mem(101,-1);
        return dfs(nums,0,mem);
    }
};