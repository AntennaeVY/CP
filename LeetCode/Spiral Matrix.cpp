class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        map<pair<int, int>, bool> visited;
        vector<int> ans;
        int i=0, j=0, rows = matrix.size(), cols = matrix[0].size();
        
        while(true) {
            while(j < cols && !visited[{i, j}]) {
                visited[{i, j}] = true;
                ans.push_back(matrix[i][j]);
                j++;
            }
            
            if (j-1 >= 0)
                j--;
            
            if (i+1 < rows)
                i++;
            
            while(i < rows && !visited[{i, j}]) {
                visited[{i, j}] = true;
                ans.push_back(matrix[i][j]);
                i++;
            }
            
            if (i-1 >= 0)
                i--;
            
            if (j-1 >= 0)
                j--;
            
            while(j >= 0 && !visited[{i, j}]) {
                visited[{i, j}] = true;
                ans.push_back(matrix[i][j]);
                j--;
            }
            
            if (j+1 < cols)
                j++;
            
            if (i-1 >= 0)
                i--;
            
            while(i >= 0 && !visited[{i, j}]) {
                visited[{i, j}] = true;
                ans.push_back(matrix[i][j]);
                i--;
            }
            
            if (i+1 < rows)
                i++;
            
            if (j+1 < cols)
                j++;
            
            if (visited[{i,j}])
                break;
        }
        
        return ans;
    }
};