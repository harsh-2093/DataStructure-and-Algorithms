class Solution {
public:
    int keys=0;

    void bfs(queue<int>&q,vector<vector<int>>& rooms,int m,vector<int>&visited)
    {
        while(q.size()>0)
        {
            int n=q.size();

            for(int k=0;k<n;k++)
            {
                vector<int>i=rooms[q.front()];
                q.pop();

                for(auto a:i)
                {
                    if(visited[a]!=1)
                    {
                        q.push(a);
                        visited[a]=1;
                        keys++;
                    }
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);

        //filling the source the keys of 0 room
        queue<int>q;
        vector<int>initial=rooms[0];
        for(int i:initial)
        {
            q.push(i);
            visited[i]=1;
            keys++;
        }

     
        visited[0]=1;
        keys++;
        bfs(q,rooms,n,visited);
        cout<<keys;
        return keys==n;


    }
};