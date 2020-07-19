class Solution {
public:
    
    bool dfs(int s, vector<vector<int>>& adj, vector<int>& stack, vector<int>& visited)
    {
        visited[s] = 1;
        
        for (int v: adj[s])
        {
            if (visited[v]==1) return true;
            if (visited[v]==0 && dfs(v, adj, stack, visited)) return true;
        }
        
        visited[s] = 2;
        stack.push_back(s);
        
        return false;
    };
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for (int i=0; i<prerequisites.size(); i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> stack;
        vector<int> visited(numCourses, 0); //tristate values (0: unvisited, 1: explored but not done, 2: explored)
        
        for (int i=0; i<numCourses; ++i)
            if (visited[i]==0 && dfs(i, adj, stack, visited)) return {};
        
        reverse(stack.begin(), stack.end());
        return stack;
    }
};