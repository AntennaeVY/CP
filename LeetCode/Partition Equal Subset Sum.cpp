class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        for(int num : nums)
            sum += num;

        if (sum%2) return false;

        vector<bool> dp(sum/2+1, false);
        dp[0] = true;

        for(int i=1; i < nums.size(); i++) {
            for(int j=sum/2; j > 0; j--) {
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp.back();
    }
};