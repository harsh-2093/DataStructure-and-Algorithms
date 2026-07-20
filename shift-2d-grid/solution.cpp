class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size()));
        int n=grid.size();
        int m=grid[0].size();
        int max_size=m*n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x=(m*i+j)%max_size;
                x+=k;
                int row=(x/m)%n;
                int col=(x%m)%m;
                ans[row][col]=grid[i][j];

            }
        }
        return ans;

    }
};