class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n);

        for(int i = 0; i < n; i++)
        {
            if(color[i]!=0)
            {
                continue;
            }
            queue<int>q;
            q.push(i);
            color[i]=1;

            while(!q.empty())
            {
                int node = q.front();
                q.pop();
                for(int j = 0; j < graph[node].size(); j++)
                {
                    int neib = graph[node][j];

                    if(color[neib]==0)
                    {
                        color[neib]= -color[node];
                        q.push(neib);
                    }
                    else if(color[neib]==color[node])
                    {
                        return false;
                    }
                }
            
            }

        }
        return true;
    }
};