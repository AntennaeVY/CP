class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    vector<int> sol(nums.size());
    sol[0] = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      sol[i] = sol[i - 1] + nums[i];
    }

    return sol;
  }
};