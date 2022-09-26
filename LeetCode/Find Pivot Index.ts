function pivotIndex(nums: number[]): number {
  const ps = Array.from(nums);

  for (let i = 1; i < ps.length; i++) {
    ps[i] = ps[i] + ps[i - 1];
  }

  for (let i = 0; i < ps.length; i++) {
    if (ps[i] - nums[i] == ps[ps.length - 1] - ps[i]) return i;
  }

  return -1;
}
