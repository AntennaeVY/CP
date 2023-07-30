class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    vector<int> ps(nums.size() + 1);
    ps[0] = 0;

    for (int i = 1; i <= nums.size(); i++) {
      ps[i] = ps[i - 1] + nums[i - 1];
    }

    for (int i = 1; i <= nums.size(); i++) {
      if (ps[i - 1] == ps.back() - ps[i]) return i - 1;
    }

    return -1;
  }
};