class Solution {
public:
    bool bfs(int src, int target, vector<vector<int>>&graph)
    {
        int n = graph.size();
        queue<pair<int,int>> q;
        q.push({src,-1});
        vector<int>visited(n+1,0);

        visited[src]=1;
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            if(node==target)
            {
                return true;
            }
            for(int i = 0; i < graph[node].size(); i++)
            {
                int neib = graph[node][i];

                if(!visited[neib])
                {
                    visited[neib]=1;
                    q.push({neib,node});
                }
                else if(neib!=parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n+1);
        
        for(int i = 0; i < n; i++)
        {
            
           int u = edges[i][0];
           int v = edges[i][1];

            if(bfs(u,v,graph))
            {
                return edges[i];
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};