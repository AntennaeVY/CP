class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), ans = 0;

        int mx = -1, s = 0;
        char curr = colors[0];

        for(int r=0; r < n; r++) {
            if (colors[r] != curr) {
                ans += s - mx;

                s = 0, mx = -1;
                curr = colors[r];
            }

            s += neededTime[r];
            mx = max(mx, neededTime[r]);
        }

        ans += s - mx;

        return ans;
    }
};