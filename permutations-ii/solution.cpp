class Solution {
public:
    vector<vector<int>>result;
    void solve(unordered_map<int,int>&freq,vector<int>&temp,vector<int>& nums)
    {
        if(temp.size()==nums.size())
        {
            result.push_back(temp);
            return;
        }

        for(auto it =freq.begin();it!=freq.end();++it)
        {
            if(it->second>0)
            {
                temp.push_back(it->first);
                it->second=it->second-1;
                solve(freq,temp,nums);
                temp.pop_back();
                it->second=it->second+1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int d:nums)
        {
            freq[d]++;
        }
        vector<int>temp;
        solve(freq,temp,nums);
        return result;
    }
};