class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>>pq;

        //pq:{sum,nums1,nums2}:

        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int sum=nums1[i]+nums2[j];

                if(pq.size()<k)
                {
                    pq.push({sum,nums1[i],nums2[j]});
                }
                else if(get<0>(pq.top())>sum)
                {
                    pq.pop();
                    pq.push({sum,nums1[i],nums2[j]});
                }
                else
                {
                    break;
                }
                
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty())
        {
            int first=get<1>(pq.top());
            int sec=get<2>(pq.top());
            ans.push_back({first,sec});
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};