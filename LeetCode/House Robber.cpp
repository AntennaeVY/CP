class Solution {
private:
    map<int,int> cache;

    int search(vector<int>& nums, int i=0) {
        if (i >= nums.size())
            return 0;

        if (cache.count(i))
            return cache[i];

        int take = nums[i] + search(nums, i+2);
        int skip = search(nums, i+1);

        cache[i] = max(take, skip);
        return cache[i];
    }
public:
    int rob(vector<int>& nums) {
        return search(nums);
        cache.clear();
    }
};