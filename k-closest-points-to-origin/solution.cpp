class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<
       tuple<int,int,int>,
       vector<tuple<int,int,int>>,
       greater<tuple<int,int,int>>
       >pq;

       //{dist,x,y};

       for(int i=0;i<points.size();i++)
       {
            int x=points[i][0];
            int y=points[i][1];
            int dist=((x*x)+(y*y));
            pq.push({dist,x,y});
            
            
       }
       vector<vector<int>>ans;

       while(!pq.empty()&& k>0)
       {
            int x=get<1>(pq.top());
            int y=get<2>(pq.top());
            ans.push_back({x,y});
            pq.pop();
            k--;
       }
       return ans ;



    }
};