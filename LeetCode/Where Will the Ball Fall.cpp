class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> ans;
        for(int i=0; i < grid[0].size(); i++) {
            int row = 0, col=i;

            while(true) {
                if (row == grid.size()) {
                    ans.push_back(col);
                    break;
                }

                if (col == grid[0].size() -1 && grid[row][col] == 1 || col == 0 && grid[row][col] == -1) {
                    ans.push_back(-1);
                    break;
                }

                if (grid[row][col] == -1 && grid[row][col-1] == 1
                    || grid[row][col] == 1 && grid[row][col+1] == -1) {
                    ans.push_back(-1);
                    break;
                }

                if (grid[row][col] == 1) 
                    col += 1;
                else
                    col -= 1;

                row += 1;
            }
        }

        return ans;
    }
};