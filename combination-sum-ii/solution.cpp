class Solution {
public: 
    vector<vector<int>>result;
    void combination(int sum,vector<int>& candidates,int target,vector<int>&temp,int index)
    {
        if(sum==target)
        {
            // sort(temp.begin(),result.end());
            result.push_back(temp);
            return;
        }

        if(sum>target)
        {
            return;
        }

        //all possible combination without redundancy
        


        for(int i=index;i<candidates.size();i++)
        {
            if(i>index && candidates[i]==candidates[i-1])continue;
            temp.push_back(candidates[i]);
            combination(sum+candidates[i],candidates,target,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(),candidates.end());

        combination(0,candidates,target,temp,0);
        

        return result;
    }
};