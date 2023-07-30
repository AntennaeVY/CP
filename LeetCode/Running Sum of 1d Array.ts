function runningSum(nums: number[]): number[] {
  const ps = Array.from(nums);

  for (let i = 1; i < ps.length; i++) {
    ps[i] += ps[i - 1];
  }

  return ps;
}
