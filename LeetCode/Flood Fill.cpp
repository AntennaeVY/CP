class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        set<string> visited;
        queue<pair<int,int>> q;
        
        int match = image[sr][sc];
        int rows = image.size() - 1;
        int cols = image[0].size() - 1;
        
        q.push({sr, sc});
        
        while(!q.empty()) {
            auto point = q.front();
            q.pop();
            
            image[point.first][point.second] = color;
            
            sr = point.first;
            sc = point.second;
            
            string node = to_string(sr) + "," + to_string(sc);
            if (visited.count(node))
                continue;
            
            visited.insert(node);
            
            if (sr > 0 && image[sr-1][sc] == match)
                q.push({sr-1, sc});
            
            if (sr < rows && image[sr+1][sc] == match)
                q.push({sr+1, sc});
            
            if (sc > 0 && image[sr][sc-1] == match)
                q.push({sr, sc-1});
            
            if (sc < cols && image[sr][sc+1] == match)
                q.push({sr, sc+1});
        }
        
        return image;
    }
};