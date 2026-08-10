class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<
        tuple<double,int,int>,
        vector<tuple<double,int,int>>,
        greater<tuple<double,int,int>>
        >pq;

        int n=arr.size()-1;
        for(int i=0;i<n;i++)
        {
            pq.push({(double)arr[i]/arr[n],i,n});
        }

        vector<vector<int>>vec;


        while(k>0 && !pq.empty())
        {
            int a=arr[get<1>(pq.top())];
            int b=arr[get<2>(pq.top())];
            int i=get<1>(pq.top());
            int j=get<2>(pq.top());
            vec.push_back({a,b});
            pq.pop();
            k--;

            if(i<j-1)
            {
                j--;
                pq.push({(double)arr[i]/arr[j],i,j});
            }
        }
        return vec.back();
    }
};