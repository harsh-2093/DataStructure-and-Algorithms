class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>Comb_sum;
        vector<int>partial;
        dfs(0,0,candidates,target,partial,Comb_sum);
        return Comb_sum;

    }
private:
    void dfs(int i,int sum,vector<int>& candidates, int target,vector<int>&partial,vector<vector<int>>&Comb_sum)
    {
        if(sum==target)
        {
            Comb_sum.push_back(partial);
            return;
        }
        if(i==candidates.size() || sum >target)return;

        partial.push_back(candidates[i]);
        dfs(i,sum+candidates[i],candidates,target,partial,Comb_sum);
        partial.pop_back();
        dfs(i+1,sum,candidates,target,partial,Comb_sum);

    }
};