func pivotIndex(nums []int) int {
    ps := make([]int, len(nums));	
	copy(ps, nums);
    
    for i := 1; i < len(nums); i++ {
        ps[i] = ps[i-1] + ps[i]
    }
    
    for i := 0; i < len(nums); i++ {
        if (ps[i] - nums[i] == ps[len(ps)-1] - ps[i]){ return i  }      
    }
    
    return -1
}