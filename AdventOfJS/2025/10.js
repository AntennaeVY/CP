/**
 * @param {string} s - The string to check
 * @returns {number} The maximum depth of the magic
 */
function maxDepth(s) {
  let sum = 0;
  let ans = 0;

  const delta = {
    "[": +1,
    "]": -1,
  };

  for (const c of s) {
    sum += delta[c];

    if (sum < 0)
      return -1;

    ans = Math.max(ans, sum);
  }

  return sum == 0 ? ans : -1;
}
