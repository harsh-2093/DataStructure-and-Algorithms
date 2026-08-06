class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;

        priority_queue<pair<int,char>>pq;

      
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }

        auto it=mpp.begin();

        while(it!=mpp.end())
        {
            char c=it->first;
            int freq=it->second;
            pq.push({freq,c});
            ++it;
        }




        string ans="";
        int n=s.size();

        char prevous='!';
        int Fq=0;
        while(!pq.empty())
        {
            char c=pq.top().second;
            int freq=pq.top().first;
            pq.pop();

            if(n%2==0)
            {
                if(freq>n/2){
                
                    return "";
                }

            }
            else
            {
                if(freq>(n+1)/2)
                {
                    return "";
                }
            }
            ans+=c;
            freq--;
            if(c!='!'&& Fq!=0)
            {
                pq.push({Fq,prevous});
            }

            prevous=c;
            Fq=freq;
            
            n--;
        }

        return ans;

    }
};