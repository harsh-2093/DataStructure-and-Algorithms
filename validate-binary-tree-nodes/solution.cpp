class Solution {
public:
    int Node_visited=0;
    bool check(int source,int n,vector<vector<int>>&adj)
    {
        vector<int>vis(n,0);
        queue<int>q;
        q.push(source);
        vis[source]=1;
        Node_visited++;

        while(q.size()>0)
        {
            int n=q.size();
            
            for(int i=0;i<n;i++)
            {

                vector<int>list=adj[q.front()];
                q.pop();

                for(int a:list)
                {
                    if(vis[a]!=0)
                    {
                        return false;
                    }
                    q.push(a);
                    vis[a]=1;
                    Node_visited++;
                }
            }
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        
        map<int,int>mpp;

        for(int i=0;i<n;i++)
        {
            mpp[i]=-1;
        }

        for(int i=0;i<n;i++)
        {
            int l=leftChild[i];
            int m=rightChild[i];

            if(l!=-1)
            {
                if(mpp[l]!=-1)
                {
                    return false;
                }
                else
                {
                    mpp[l]=i;
                }
                
            }
            if(m!=-1)
            {
                if(mpp[m]!=-1)
                {
                    return false;
                }
                else
                {
                    mpp[m]=i;
                }
            }
        }
        //for identigying root node
        vector<vector<int>>adj(n);
        int Parent_node=-1;
        int rootNode=0;
        auto it =mpp.begin();
        while(it!=mpp.end())
        {
            if(it->second==-1)rootNode++;
            int child=it->first;
            int parent=it->second;
            if(parent!=-1)
            {
                adj[parent].push_back(child);
            }
            else
            {
                Parent_node=child;
            }
            ++it;

        }
        for(int j=0;j<adj.size();j++)
        {
            cout<<j<<"->";
            for(int i=0;i<adj[j].size();i++)
            {
                cout<<adj[j][i]<<" ";
            }
            cout<<endl;
        }
        if(rootNode!=1)return false;
        cout<<"rootNode"<<Parent_node;
        if(check(Parent_node,n,adj)==false || Node_visited!=n){
            return false;
        }

        return true;

        

    }
};