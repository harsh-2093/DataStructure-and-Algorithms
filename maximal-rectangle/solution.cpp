class Solution {
public:
 void find_nsr(vector<int>& heights,vector<int>& nsr)
    {
        stack<int>st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nsr[i]=heights.size();
            }
            else
            {
                nsr[i]=st.top();
            }
            st.push(i);
        }

    }
    void find_nsl(vector<int>& heights,vector<int>& nsl)
    {
        stack<int>st;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                st.pop();
            }
            if(st.empty())
            {
                nsl[i]=-1;
            }
            else
            {
                nsl[i]=st.top();
            }
            st.push(i);
        }

        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int>NSL(matrix[0].size());
        vector<int>NSR(matrix[0].size());
        vector<int>heights(matrix[0].size());

        int Area=0;

        for(int i=0;i<matrix.size();i++)
        {
            
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                {
                    heights[j]=0;
                }
                else
                {
                    heights[j]+=matrix[i][j]-'0';
                }
            }
            find_nsl(heights,NSL);
            find_nsr(heights,NSR);

       
        for(int i=0;i<heights.size();i++)
        {
            int len=0;
            len=(i-NSL[i])+(NSR[i]-i)-1;

            int area=len*heights[i];
            Area=max(area,Area);

        }

        }
        return Area;
    }
};