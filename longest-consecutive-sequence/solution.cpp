class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        unordered_set<int>st;
        int len=1;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
        }

        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end())
                {
                    count++;
                    x++;
                }
                len=max(count,len);
            }

        }
        return len;
        
    }
};