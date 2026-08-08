class Solution {
public:
    void merge(vector<int>& nums,int l,int mid,int r)
    {
        int k=l;
        vector<int>left;
        vector<int>right;
        int l_idx=l;
        int r_idx=mid+1;

        while(l_idx<=mid)
        {
            left.push_back(nums[l_idx++]);
        }
        while(r_idx<=r)
        {
            right.push_back(nums[r_idx++]);
        }
        
        int i=0;
        int j=0;

        while(i<left.size() && j<right.size())
        {
            if(left[i]<=right[j])
            {
                nums[k++]=left[i++];
            }
            else
            {
                nums[k++]=right[j++];
            }
        }
        while(i<left.size())
        {
            nums[k++]=left[i++];
        }
        while(j<right.size())
        {
            nums[k++]=right[j++];
        }
        
    }
    void solve(vector<int>& nums,int l,int r)
    {
        if(l==r)return;
        int mid=(l+r)/2;
        solve(nums,l,mid);
        solve(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    vector<int> sortArray(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;

        solve(nums,l,r);

        return nums;
    }
};