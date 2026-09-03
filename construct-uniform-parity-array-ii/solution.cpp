class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val=*min_element(nums1.begin(),nums1.end());

        if(min_val%2==1)return true;
        else
        {
                    for(int d:nums1)
                    {
                        if(d%2==1)return false;
                    }
        }
        return true;

    }
};