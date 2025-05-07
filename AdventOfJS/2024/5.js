function organizeShoes(shoes) {
  let p = {}
  const ans = []

  for (const { type: t, size: s } of shoes) {
      p[s] ??= [0, 0]
      p[s][0] += +(t == 'I')
      p[s][1] += +(t == 'R')

      if (p[s][0] >= 1 && p[s][1] >= 1) {
        ans.push(s)
        p[s][0] -= 1, p[s][1] -= 1
      }
  }

  return ans
}
