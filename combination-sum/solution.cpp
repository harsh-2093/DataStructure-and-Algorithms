class Solution {
public:
    vector<vector<int>>result;
    void combination(int sum,vector<int>& candidates,int target,vector<int>&temp,int index)
    {
        if(sum==target)
        {
            // sort(temp.begin(),temp.end());
            result.push_back(temp);
            return;
        }


        //base case
        if(sum>target)
        {
            return;
        }

        

        //all possible combination with duplicates
        for(int i=index;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            combination(sum+candidates[i],candidates,target,temp,i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        int sum=0;
        combination(sum,candidates,target,temp,0);
        // vector<vector<int>>res(result.begin(),result.end());
        return result;
    }
};