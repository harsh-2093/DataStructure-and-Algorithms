class Solution {
public:
    int ans;
    void solve(string tiles,int index,string curr,set<int>&freq)
    {
        if(!curr.empty())
        {
            ans++;
        }
        if(curr.size()==tiles.size())return;



        for(int i=0;i<tiles.size();i++)
        {
            if(i>0 && tiles[i]==tiles[i-1]&&freq.find(i-1)==freq.end() )continue;
            if(freq.find(i) != freq.end())
    continue;

            freq.insert(i);
            curr+=tiles[i];

            solve(tiles,index+1,curr,freq);
            curr.pop_back();
            freq.erase(i);
        }
        
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        set<int>freq;
       solve(tiles,0,"",freq);
       return ans;
    }
};