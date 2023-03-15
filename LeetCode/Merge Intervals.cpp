class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){
            if (x[0] == y[0])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        for(int i=1; i < intervals.size(); i++) {
            auto &y = intervals[i-1];
            auto &x = intervals[i];

            if (y[0] <= x[0] && y[1] >= x[1]) {
                intervals.erase(intervals.begin()+i, intervals.begin()+i+1);
                i--;
                continue;
            }
        
            if (y[1] >= x[0] && y[1] <= x[1]) {
                y[0] = min(y[0], x[0]);
                y[1] = max(x[1], y[1]);
                intervals.erase(intervals.begin()+i, intervals.begin()+i+1);
                i--;
                continue;
            }
        }

        return intervals;
    }
};