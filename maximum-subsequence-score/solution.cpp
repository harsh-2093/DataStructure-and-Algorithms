class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>arr;
        //{num2,num1}
        for(int i=0;i<nums1.size();i++)
        {
            arr.push_back({nums2[i],nums1[i]});
        }

        sort(arr.begin(),arr.end(),[](const pair<int,int>&a,const pair<int,int>&b)
        {
            return a.first>b.first;
        });

        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=0;
        long long max_result=0;

        for(int i=0;i<arr.size();i++)
        {
            int min_val=arr[i].first;


            pq.push(arr[i].second);
             sum+=arr[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                max_result=max(max_result,sum*min_val);

            }
        }
        
        return max_result;
    }
};