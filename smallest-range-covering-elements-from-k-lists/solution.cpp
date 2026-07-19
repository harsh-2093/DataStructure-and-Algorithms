class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        >pq;

        int greatest_value=INT_MIN;
        int diffrence=INT_MAX;
        int left=0;
        int right=0;

        for(int i=0;i<nums.size();i++)
        {
            pq.push({nums[i][0],i,0});
            if(nums[i][0]>greatest_value)
            {
                greatest_value=nums[i][0];
            }

        }
        diffrence=greatest_value-get<0>(pq.top());
        left=get<0>(pq.top());
        right=greatest_value;

        while(true)
        {
            int val=get<0>(pq.top());
            int row=get<1>(pq.top());
            int index=get<2>(pq.top());
            if(index+1>=nums[row].size())
            {
                break;
            }
            else
            {
                pq.pop();
                pq.push({nums[row][index+1],row,index+1});
                if(nums[row][index+1]>greatest_value)
                {
                    greatest_value=nums[row][index+1];
                    // greatest_value=get<0>(pq.top());
                }
                if(greatest_value-get<0>(pq.top())<diffrence)
                {
                    left=get<0>(pq.top());
                    right=greatest_value;
                    diffrence=greatest_value-get<0>(pq.top());
                }
                
            }
        }
        return {left,right};
    }
};