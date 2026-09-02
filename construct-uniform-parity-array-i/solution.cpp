class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       if(nums1.size()==1)return true;
        bool final_odd=true;
        bool final_even =true;
        for(int i=0;i<nums1.size();i++)
        {
            bool odd=false;
            bool even =false;
            for(int j=0;j<nums1.size();j++)
            {
                if(i==j)continue;
                if(nums1[i]%2!=0 || (nums1[i]-nums1[j])%2!=0)
                {
                    odd=true;
                }
                if(nums1[i]%2==0 || (nums1[i]-nums1[j])%2==0)
                {
                    odd=true;
                }
            }
            if(odd==false)final_odd=false;
            if(even==false)final_even=false;
        }
        return (final_odd || final_even);
    }
};