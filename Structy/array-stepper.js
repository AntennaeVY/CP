const arrayStepper = (nums, from=0, cache={}) => {
  if (cache[from] !== undefined)
    return cache[from];
  
  if (from == nums.length-1)
      return true;
  
  for(let i=1; i <= nums[from]; i++) {
    if (from + i < nums.length && arrayStepper(nums, from+i, cache)) {
      cache[from] = true;
      return true;
    }
  }
    
  cache[from] = false;
  return false;
};

module.exports = {
  arrayStepper,
};
