class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while(l + 1 < r) {
            int mid = l + (r-l)/2;

            if (nums[mid] < nums[r])
                r = mid;
            else 
                l = mid;
        }



        return max(binSearch(nums, r, nums.size()-1, target), binSearch(nums, 0, l, target));
    }

    int binSearch(vector<int>& nums, int l, int r, int target) {
        while(l <= r) {
            int mid = l + (r-l)/2;

            if (nums[mid] == target) 
                return mid;

            if (nums[mid] > target)
                r = mid-1;
            else 
                l = mid+1;
        }

        return -1;
    }
};