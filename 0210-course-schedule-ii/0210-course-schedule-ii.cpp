class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i = 0; i < n; i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0; i < adj[node].size(); i++)
            {
                int next = adj[node][i];
                indegree[next]--;
                if(indegree[next]==0)
                {
                    q.push(next);
                }
            }
        }
        if(ans.size()==numCourses)
        {
            return ans;
        }
        return {};
    }
};