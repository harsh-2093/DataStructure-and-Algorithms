class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>combination;
        vector<int>partial;
        dfs(1,n,k,partial,combination);
        return combination;

    
    }
private:
    void dfs(int i,int n,int k, vector<int>&partial,vector<vector<int>>&combination)
    {
        if(partial.size()==k)
        {
            combination.push_back(partial);
            return;
        }
        if(i>n)return;

        partial.push_back(i);
        dfs(i+1,n,k,partial,combination);
        partial.pop_back();
        dfs(i+1,n,k,partial,combination);

    }
};