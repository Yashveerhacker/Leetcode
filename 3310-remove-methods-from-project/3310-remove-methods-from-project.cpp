class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<bool>&visited)
    {
        visited[node] = true;
        for(int i = 0; i < adj[node].size(); i++)
        {
            int neib = adj[node][i];
            if(!visited[neib])
            {
                dfs(neib,adj,visited);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        int m = invocations.size();
        for(int i = 0; i < m; i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
        }
        vector<bool>visited(n,false);

        dfs(k,adj,visited);

        for(int i = 0; i < m; i++)
        {
            int u = invocations[i][0];
            int v = invocations[i][1];

            if(!visited[u] && visited[v])
            {
                vector<int>ans;
                for(int j = 0; j < n; j++)
                {
                    ans.push_back(j);
                }
                return ans;
            }
        }
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};