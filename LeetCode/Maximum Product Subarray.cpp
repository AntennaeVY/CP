class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int min_p = 1, max_p = 1;

        for(int i=0; i < nums.size(); i++) {
           int temp = max_p;

           max_p = max(max_p * nums[i], min_p * nums[i]);
           max_p = max(max_p, nums[i]);

           min_p = min(min_p * nums[i], temp * nums[i]);
           min_p = min(min_p, nums[i]);

           ans = max(ans, max(min_p, max_p));
        }

        return ans;
    }
};