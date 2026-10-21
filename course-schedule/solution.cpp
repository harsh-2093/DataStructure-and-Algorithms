class Solution {
public:
    int takenCourses=0;

    void bfs(int numCourses, vector<vector<int>>&adj, queue<int>&q, vector<int>&indegree)
    {
        while(q.size()>0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                vector<int>curr=adj[q.front()];
                q.pop();
                takenCourses++;

                for(auto i:curr)
                {
                    indegree[i]--;
                    if(indegree[i]==0)
                    {
                        q.push(i);

                    }
                }
            }
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create the adj list
        vector<vector<int>>adj(numCourses);
        for(auto a:prerequisites)
        {
            int parent =a[1];
            int child=a[0];

            adj[parent].push_back(child);
        }

        //we store the indegree foe the so.
        vector<int>indegree(numCourses,0);
        for(int a=0;a<prerequisites.size();a++)
        {
            indegree[prerequisites[a][0]]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses ;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }

        bfs(numCourses,adj,q,indegree);
        if(takenCourses==numCourses)return true;
        return false;

    }
};