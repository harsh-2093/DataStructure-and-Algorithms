class Solution {
public:
    set<string>ans;
    void solve(string tiles,int index,string curr,set<int>&freq)
    {
                if(!curr.empty())
        {
            ans.insert(curr);
        }
        if(curr.size()==tiles.size())return;



        for(int i=0;i<tiles.size();i++)
        {
            if(freq.find(i)!=freq.end())continue;

            freq.insert(i);
            curr+=tiles[i];

            solve(tiles,index+1,curr,freq);
            curr.pop_back();
            freq.erase(i);
        }
        
    }
    int numTilePossibilities(string tiles) {
        set<int>freq;
       solve(tiles,0,"",freq);
       return ans.size();
    }
};