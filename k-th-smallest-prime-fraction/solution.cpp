class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        //{fraction,a[i],a[j]}
        vector<tuple<float,int,int>>Vec;
        

        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                Vec.push_back({arr[i]/(float)arr[j],arr[i],arr[j]});
            }
        }
        sort(Vec.begin(),Vec.end());

        int a=get<1>(Vec[k-1]);
        int b=get<2>(Vec[k-1]);
        return {a,b};
    }
};