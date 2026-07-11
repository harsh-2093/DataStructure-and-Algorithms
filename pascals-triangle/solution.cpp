class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>result;
        for(int i=1;i<=n;i++)
        {
            vector<int>temp;
            int ans=1;
            temp.push_back(ans);
            for(int j=1;j<i;j++)
            {
                ans*=i-j;
                ans/=j;
                temp.push_back(ans);
            }
            result.push_back(temp);
        }
        return result;
    }
};