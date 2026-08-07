class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>mpp(26,0);
        priority_queue<int>pq;

        for(int i=0;i<tasks.size();i++)
        {
            mpp[tasks[i]-'A']++;
        }

        for(int d:mpp)
        {
            if(d>0)
            {
                pq.push(d);
            }
        }
        int ans=0;

        while(!pq.empty())
        {
            vector<int>temp;

            for(int i=1;i<=n+1;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(int d:temp)
            {
                if(d>0)
                {
                    pq.push(d);
                }
            }

            if(pq.empty())
            {
                ans+=temp.size();
            }
            else
            {
                ans+=n+1;
            }
        }
        return ans;
    }
};