func longestSubarray(nums []int) int {
    max_element := math.MinInt
    current, ans := 0, 0
    
    for i:=0; i < len(nums); i++ {
        if nums[i] > max_element {
            max_element = nums[i]
        }
    }
    
    for i:=0; i < len(nums); i++ {
        if (nums[i] == max_element) {
            current++
        } else {
            current = 0
        }
        
        if (current > ans) {
            ans = current
        }
    }
    
    return ans
}