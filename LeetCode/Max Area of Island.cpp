class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        visited.assign(n, vector<bool>(m, false));

        int mx = 0;

        for(int i=0; i < n; i++) {
            for(int j=0; j < m; j++) {
                mx = max(mx, dfs(grid, i, j));
            }
        }

        return mx;
    }
private:
    vector<vector<bool>> visited;

    int dfs(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j])
            return 0;

        int cnt = 1;
        visited[i][j] = true;

        cnt += dfs(grid, i, j+1);
        cnt += dfs(grid, i-1, j);
        cnt += dfs(grid, i, j-1);
        cnt += dfs(grid, i+1, j);

        return cnt;
    }
};