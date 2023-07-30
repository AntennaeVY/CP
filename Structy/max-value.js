const maxValue = (nums) => {
  let max = -Infinity;
  
  for (let num of nums) {
    if (num > max) max = num;
  }
  
  return max;
};

module.exports = {
  maxValue,
};
