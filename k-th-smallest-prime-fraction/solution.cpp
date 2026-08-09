class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //{fraction,a[i],a[j]}
        priority_queue<
        tuple<float,int,int>
        >pq;
        

        for(int i=0;i<arr.size();i++)
        {
            for(int j=arr.size()-1;j>i;j--)
            {
                if(pq.size()<k)
                {
                    pq.push({arr[i]/(float)arr[j],arr[i],arr[j]});
                }
                else if(pq.size()==k && get<0>(pq.top())>arr[i]/(float)arr[j])
                {
                  pq.pop();  
                  pq.push({arr[i]/(float)arr[j],arr[i],arr[j]});
                }
                else
                {
                    break;
                }
                
            }
        }
        int a=get<1>(pq.top());
        int b=get<2>(pq.top());
        return {a,b};
    }
};