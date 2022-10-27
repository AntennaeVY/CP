class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
            
        long long lastArrow = points[0][1];
        long long ans = 1;
            
        for (int i=1; i < points.size(); i++) {
            if (points[i][0] > lastArrow) {
                ans++;
                lastArrow = points[i][1];
            }
        }
        
        return ans;
    }
};