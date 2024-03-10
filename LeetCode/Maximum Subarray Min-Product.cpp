class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<long long> prefix_sum(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
        }

        nums.push_back(-1);

        stack<int> s;
        s.push(-1);

        long long ans = 0;

        for(int i=0; i <= n; i++) {
            while(s.top() != -1 && nums[s.top()] > nums[i]) {
                long long num = nums[s.top()];
                s.pop();

                ans = max(ans, num*(prefix_sum[i] - prefix_sum[s.top()+1]));
            }

            s.push(i);
        }

        return ans % int(1e9 + 7);
    }
};