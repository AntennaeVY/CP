class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> delta(200001, 0);
        int n = nums.size();

        for(int i=0; i < n/2; i++) {
            int m = min(nums[i] + 1, nums[n-1-i] + 1);
            int M = max(nums[i] + limit, nums[n-1-i] + limit);
            int S = nums[i] + nums[n-1-i];

            delta[S] -= 1;
            delta[S+1] += 1;

            delta[m] -= 1;
            delta[M+1] += 1;
        }

        int ans = n, current = n;

        for(int i=2; i <= 2*limit; i++) {
            current += delta[i];

            ans = min(ans, current);
        }

        return ans;
    }
};