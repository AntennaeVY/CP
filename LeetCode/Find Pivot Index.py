class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        ps = [nums[0]] * len(nums)
        
        for i in range(1, len(nums)):
            ps[i] = ps[i-1] + nums[i]
        
        for i in range(len(nums)):
            if (ps[i] - nums[i] == ps[-1] - ps[i]): return i
            
        return -1
        