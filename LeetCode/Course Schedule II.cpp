class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> graph;
        map<int, bool> can, visited;

        vector<int> ans;

        for(auto edge : prerequisites) {
            graph[edge[0]].push_back(edge[1]);
        }

        function<void(int)> dfs;
        dfs = [&](int root){
            if (visited[root])
                return; 

            visited[root] = true;

            bool ok = true;

            for (auto node : graph[root]) {
                if (!visited[node])
                    dfs(node);

                ok &= can[node];
            }

            can[root] = ok;

            if (ok)
                ans.push_back(root);
        };

        for(int i=0; i < numCourses; i++) {
            dfs(i);
        }

        if (ans.size() == numCourses)
            return ans;
        else
            return {};
    }
};