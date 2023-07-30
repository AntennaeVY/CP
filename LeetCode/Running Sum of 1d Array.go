func runningSum(nums []int) []int {
    ps := make([]int, len(nums))
    copy(ps, nums)
    
    for i:=1; i < len(nums); i++ {
        ps[i] += ps[i-1]
    }
    
    return ps
}