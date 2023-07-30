func sortPeople(names []string, heights []int) []string {
    namesToH := make(map[int]string)
    
    for i:=0; i < len(names); i++ {
        namesToH[heights[i]] = names[i]
    }
    
    sort.Sort(sort.Reverse(sort.IntSlice(heights)))
    sol := make([]string, len(names))
    
    for i:=0; i < len(names); i++ {
        sol[i] = namesToH[heights[i]]
    }
     
    return sol
}