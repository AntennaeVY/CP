class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_element = max(nums)
        mx = cnt = 0
        
        for num in nums:
            if num == max_element:
                cnt+=1
            else:
                cnt=0
            
            mx = max(mx, cnt)
        
        return mx