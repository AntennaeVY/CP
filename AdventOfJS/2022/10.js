function checkJump(heights) {
  let i;

  for (i = 1; i < heights.length; i++) {
    if (heights[i] < heights[i - 1])
      break;
  }

  if (i == heights.length || heights.length == 0 || i == 1)
    return false;

  for (; i < heights.length; i++) {
    if (heights[i] > heights[i - 1])
      return false;
  }

  return true;
}

console.log(checkJump([1, 2]))
console.log(checkJump([2]))
console.log(checkJump([]))
console.log(checkJump([2, 1]))
