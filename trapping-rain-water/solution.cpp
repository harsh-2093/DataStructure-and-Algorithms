class Solution {
public:
    int trap(vector<int>& height) {
        stack<pair<int,int>>st;

        for(int i=0;i<height.size();i++)
        {
            if(st.empty())
            {
                st.push({height[i],height[i]});
            }
            else if(height[i]<st.top().second)
            {
                st.push({height[i],st.top().second});
            }
            else
            {
                st.push({height[i],height[i]});
            }
        }
        int rightmax=-1;
        int ans=0;
        int i=height.size()-1;
        while(!st.empty())
        {
            if(st.size()==height.size())
            {
                rightmax=st.top().first;
                ans+=min(rightmax,st.top().second)-height[i];
                i--;
            }
            else
            {
                rightmax=max(st.top().first,rightmax);
                ans+=min(rightmax,st.top().second)-height[i];
                i--;
            }
            st.pop();
        }
        return ans;
    }
};