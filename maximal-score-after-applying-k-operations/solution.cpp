class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long >pq;
        long long  sum=0;


        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }

        while(!pq.empty() && k--)
        {
            long long value=pq.top();
            sum+=value;
            pq.pop();
            long long new_val=ceil(value/3.0);
            
            pq.push(new_val);
        }
        return sum;
    }
};