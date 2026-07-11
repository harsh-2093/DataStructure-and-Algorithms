class Solution {
public:
    vector<vector<int>>result;
    void permute(int index,vector<int>& nums,vector<int>&temp,vector<int>&used)
    {
        //base case
        if(temp.size()==nums.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(used[i]==1)continue;
            temp.push_back(nums[i]);
            used[i]=1;
            permute(i+1,nums,temp,used);
            temp.pop_back();
            used[i]=0;
            // permute(i+1,nums,temp);


        }




    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<int> used(nums.size(), 0);
        permute(0,nums,temp,used);
        return result;
    }
};