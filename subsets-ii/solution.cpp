class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>powerset;
        vector<int>partial;
        dfs(nums,0,partial,powerset);
        return powerset;

    }
private:
    void dfs(vector<int>& nums,int i,vector<int>&partial,vector<vector<int>>&powerset)
    {
        if(i==nums.size())powerset.push_back(partial);
        else
        {
            int val=nums[i];
            int k=1;
            while(i+k<nums.size() && nums[i+k]==val)k++;
            dfs(nums,i+k,partial,powerset);

            partial.push_back(nums[i]);
            dfs(nums,i+1,partial,powerset);
            partial.pop_back();
        }
    }
};