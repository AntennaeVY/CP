class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> m;
        
        for(int i=0; i < nums.size(); i++) {
            m[nums[i]].push_back(i);
        }

        vector<int> ans;
        
        for(int i=0; i < nums.size(); i++) {
            if (target-nums[i] == nums[i] && m[nums[i]].size() <= 1)
                continue;
            
            if (m[target-nums[i]].size() == 0)
                continue;
            
            int first = m[nums[i]].back();
            m[nums[i]].pop_back();
            
            int second = m[target-nums[i]].back();
            
            ans.push_back(first);
            ans.push_back(second);
            break;
        }
        
        return ans;
    }
};