class Solution {
public:
void fill_rse(vector<int>& heights,vector<int>&rse)
    {
        stack<int>st;
        int n=heights.size()-1;

        for(int i=n;i>=0;i--)
        {
            if(st.empty())
            {
                rse[i]=n+1;

            }
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                rse[i]=n+1;
            }
            else
            {
                rse[i]=st.top();
            }
            st.push(i);

        }

    }
    void fill_lse(vector<int>& heights,vector<int>&lse)
    {
        stack<int>st;

        for(int i=0;i<heights.size();i++)
        {
            if(st.empty())
            {
                lse[i]=-1;

            }
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                lse[i]=-1;
            }
            else
            {
                lse[i]=st.top();
            }
            st.push(i);

        }
        return;

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>lse(heights.size());
        vector<int>rse(heights.size());

        fill_lse(heights,lse);
        fill_rse(heights,rse);
        int max_area=-1;

        for(int i=0;i<heights.size();i++)
        {
            int len=(i-lse[i])+(rse[i]-i)-1;
            max_area=max(max_area,len*heights[i]);
        }
        return max_area;

    }
};