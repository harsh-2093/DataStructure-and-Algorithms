class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>mpp;
        //{value,freq}:

        for(int d:hand)
        {
            mpp[d]++;
        }
        int ans=0;

       
        while(!mpp.empty())
        {
            auto it=mpp.begin();
            int cnt=0;
            int prev=-1;
            while(it!=mpp.end())
            {
                if(cnt==groupSize)break;
                if(it->second==0)
                {
                    mpp.erase(it);
                    break;
                }

                if(prev==-1)
                {
                    if(it->second>0)
                    {
                        prev=it->first;
                        cnt++;
                        it->second--;
                    }
                }
                else if(it->first==prev+1 &&it->second>0)
                {
                    prev=it->first;
                    cnt++;
                    it->second--;
                }
                ++it;
            }
            if(cnt==groupSize)
            {
                ans++;
            }
        }

        if(ans==hand.size()/groupSize)return true;
        return false;
        
        
    }
};