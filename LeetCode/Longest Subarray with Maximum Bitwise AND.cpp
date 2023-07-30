class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int num = *max_element(nums.begin(), nums.end());
    int mx = 0, cnt = 0;
    
    for(int i=0; i < nums.size(); i++) {
        if (nums[i] == num)
            cnt++;
        else 
            cnt = 0;
        
        mx = max(mx, cnt);
    }
    
    return mx;
    }
};