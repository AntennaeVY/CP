function longestSubarray(nums: number[]): number {
  const max_element = Math.max(...nums);

  let count = 0,
    max = 0;

  for (const num of nums) {
    if (num == max_element) count++;
    else count = 0;

    max = Math.max(max, count);
  }

  return max;
}
