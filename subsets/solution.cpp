class Solution {
public:
    vector<vector<int>>result;
    void solve(int index,vector<int>& nums,vector<int>&temp)
    {
        result.push_back(temp);

        if(temp.size()==nums.size()|| index==nums.size())
        {
            return ;
        }
            for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            solve(i+1,nums,temp);
            temp.pop_back();
            }





    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<bool>used;
        solve(0,nums,temp);       
        return result;  
    }
};