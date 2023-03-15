class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto x = newInterval;

        if (intervals.empty()) {
            intervals.push_back(x);
            return intervals;
        }

        for(int i=0; i < intervals.size(); i++) {
            vector<int> &y = intervals[i];

            if (y[0] <= x[0] && y[1] >= x[1])
                break;

            if (x[0] <= y[0] && x[1] >= y[1]) {
                y[0] = x[0];
                y[1] = x[1];

                break;
            }

            if (x[0] <= y[0] && (x[1] >= y[0] && x[1] <= y[1]) ) {
                y[0] = x[0];
                break;
            }

            if (x[0] >= y[0] && (y[1] >= x[0] && y[1] <= x[1])) {
                y[1] = x[1];
                break;
            }

            if (x[1] < y[0]) {
                intervals.insert(intervals.begin()+i, x);
                break;
            }

            if (i == intervals.size()-1 && x[0] > y[1]) {
                intervals.push_back(x);
                break;
            }
        }

        for(int i=1; i < intervals.size(); i++) {
            auto &y = intervals[i-1];
            auto &x = intervals[i];

            if (y[0] <= x[0] && y[1] >= x[1]) {
                intervals.erase(intervals.begin()+i, intervals.begin()+i+1);
                i--;
                continue;
            }
        
            if (y[1] >= x[0] && y[1] <= x[1]) {
                y[1] = x[1];
                intervals.erase(intervals.begin()+i, intervals.begin()+i+1);
                i--;
                continue;
            }
        }

        return intervals;
    }
};