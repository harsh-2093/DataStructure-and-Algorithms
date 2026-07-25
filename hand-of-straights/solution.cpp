class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        unordered_map<int,int>mpp;
        //{value,freq}:
        priority_queue<int ,vector<int>,greater<int>>pq;

        for(int d:hand)
        {
            mpp[d]++;
        }

        auto it=mpp.begin();
        while(it!=mpp.end())
        {
            pq.push(it->first);
            ++it;
        }

        int ans=0;

        while(!pq.empty())
        {
            vector<int>val;
            
            int cnt=0;
            int prev=-1;
            while(!pq.empty())
            {
                if(cnt==groupSize)
                {
                    break;
                }

                if(prev==-1)
                {
                    prev=pq.top();
                    mpp[prev]--;
                    if(mpp[prev]!=0)
                    {
                        val.push_back(prev);
                    }
                    cnt++;
                }
                else
                {
                    if(pq.top()==prev+1)
                    {
                        mpp[pq.top()]--;
                        if(mpp[pq.top()]!=0)
                        {
                            val.push_back(pq.top());
                        }
                        cnt++;
                        prev=pq.top();
                    }
                }
                pq.pop();
                if(cnt==groupSize)
                {
                    ans++;
                }

            }
                            for(int d:val)
                {
                     pq.push(d);
                }
        }

        if(ans==hand.size()/groupSize)return true;
        return false;
        
        
    }
};