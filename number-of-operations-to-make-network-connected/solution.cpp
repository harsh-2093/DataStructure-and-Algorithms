class Solution {
public: 
    void bfs(int source,vector<int>&vis,vector<vector<int>>&adj)
    {
        queue<int>q;
        q.push(source);
        vis[source]=1;

        while(q.size()>0)
        {
            vector<int>list=adj[q.front()];
            q.pop();

            for(int i:list)
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()< n-1)return -1;

        vector<vector<int>>adj(n);
        vector<int>vis(n,0);

        for(auto i:connections)
        {
            int x=i[0];
            int y=i[1];

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int component=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                component++;
                bfs(i,vis,adj);
            }
        }
        return component-1;


    }
};