/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    Solution() : importances(2000+3), visited(2000+3) {}

    int getImportance(vector<Employee*> employees, int id) {
        for(auto e : employees) {
            importances[e->id] = e->importance;

            for(auto sub : e->subordinates) {
                graph[e->id].push_back(sub);  
            }
        }

        return dfs(id);
    }
private:
    vector<int> importances;
    vector<bool> visited;
    map<int, vector<int>> graph;

    int dfs(int id) {
        visited[id] = true;
        int cnt = importances[id];

        for(auto subId : graph[id]) {
            if (!visited[subId])
                cnt += dfs(subId);
        }

        return cnt;
    }
};