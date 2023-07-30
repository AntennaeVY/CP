class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = 1e9, ans = -1;
        sort(nums.begin(), nums.end());

        for(int i=0; i < size(nums); i++) {
            int j = i+1, k = size(nums) - 1;

            while(k > j) {
                int x = nums[i], y = nums[j], z = nums[k];
                
                if (abs(target - x - y - z) < min_diff) {
                    ans = x+y+z;
                    min_diff = abs(target - x - y - z);
                }

                if (x + y + z > target)
                    k--;
                else if (x + y + z < target)
                    j++;
                else
                    break; 
            }
        }

        return ans;
    }
};