class Solution {
public:
    set<vector<int>>result;
    void solve(int index,vector<int>& nums,vector<int>&temp,vector<bool>&used)
    {
        result.insert(temp);

        if(temp.size()==nums.size()|| index==nums.size())
        {
            return ;
        }
        for(int i=index;i<nums.size();i++){
            if(used[i]==true)continue;
            temp.push_back(nums[i]);
            used[i]=true;
            solve(i+1,nums,temp,used);
            temp.pop_back();
            used[i]=false;
            }





    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<bool>used(nums.size(),false);
        solve(0,nums,temp,used);
        vector<vector<int>>res(result.begin(),result.end());
        return res;
    }
};