class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums,int index,vector<int>&curr)
    {
        if(index==nums.size())
        {
            ans.push_back(curr);
            return;
        }

        //take it
        curr.push_back(nums[index]);
        solve(nums,index+1,curr);
        curr.pop_back();

        solve(nums,index+1,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        solve(nums,0,curr);
        return ans;
    }
};