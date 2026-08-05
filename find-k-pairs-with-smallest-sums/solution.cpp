class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
    
        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        >pq;
        //pq{sum,A[i],B[j]}

         vector<vector<int>>ans;
        set<pair<int,int>>st;
        //{A[i],B[j]}

        int i=0;
        int j=0;

        pq.push({A[i]+B[j],i,j});

        
       
        while(k>0 && !pq.empty())
        {
            ans.push_back({A[get<1>(pq.top())],B[get<2>(pq.top())]});\
            k--;
            i=get<1>(pq.top());
            j=get<2>(pq.top());
            
            if(i+1<A.size() && st.find({i+1,j})==st.end())
            {
                pq.push({A[i+1]+B[j],i+1,j});
                st.insert({i+1,j});
            }
            if(k>0 && j+1<B.size() && st.find({i,j+1})==st.end())
            {
                pq.push({A[i]+B[j+1],i,j+1});
                st.insert({i,j+1});
            }
            pq.pop();
        }

        return ans;

    }
};