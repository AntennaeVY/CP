class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> grid(n+1, vector<int>(n+1, 0));

        for(int i=0; i < dig.size(); i++) {
            int x = dig[i][0], y = dig[i][1];

            grid[x+1][y+1] = 1;
        }

        for(int i=1; i <= n; i++) {
            for(int j=1; j <= n; j++) {
                grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
            }
        }

        int cnt = 0;

        for (auto artifact : artifacts) {
            int r1 = artifact[0], c1 = artifact[1];
            int r2 = artifact[2], c2 = artifact[3];

            int area = (r2-r1+1)*(c2-c1+1);
            int dug = grid[r2+1][c2+1] - grid[r1][c2+1] - grid[r2+1][c1] + grid[r1][c1];
            cnt += (dug == area);            
        }

        return cnt;
    }
};