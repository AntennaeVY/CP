function optimizeIntervals(intervals) {
  intervals.sort((a, b) => a[0] - b[0]);

  const ans = [intervals[0]];

  for(const r of intervals.slice(1)) {
    const last = ans.at(-1);
    
    if (r[0] >= last[0] && r[0] <= last[1])
      ans[ans.length - 1][1] = Math.max(r[1], last[1]);
    else
      ans.push(r);
  }

  return ans;
}
