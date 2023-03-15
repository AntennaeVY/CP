class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int, vector<int>> graph;

        for(auto route : routes) {
           for(int i=0; i < route.size(); i++) {
               for(int j=i+1; j < route.size(); j++) {
                   graph[route[i]].push_back(route[j]);
                   graph[route[j]].push_back(route[i]);
               }
           }
        }

        vector<bool> visited(1e6+1, false);
        vector<int> distance(1e6+1, INT_MAX);
        queue<int> q;

        q.push(source);
        distance[source] = 0;

        while(!q.empty()) {
            int current = q.front();
            q.pop();
            
            visited[current] = true;

            if (current == target)
                break;

            for(auto node : graph[current]) {
                if (visited[node])
                    continue;

                distance[node] = min(distance[current] + 1, distance[node]);

                q.push(node);
            }
        }

        if (visited[target])
            return distance[target];
        else
            return -1;
    }
};