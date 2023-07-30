class Solution {
public:
    int dfs(vector<vector<char>> &grid, int i, int j, set<string> &visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return 0;
        
        string node = to_string(i) + "," + to_string(j);
        
        if (visited.count(node)) return 0;
        
        visited.insert(node);
        
        dfs(grid, i-1, j, visited);
        dfs(grid, i+1, j, visited);
        dfs(grid, i, j-1, visited);
        dfs(grid, i, j+1, visited);
        
        return 1;
    }
        
    int numIslands(vector<vector<char>>& grid) {
        set<string> visited;
        int cnt = 0;
        
        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[0].size(); j++) {
                cnt += dfs(grid, i, j, visited);
            }
        }
        
        return cnt;
    }
};