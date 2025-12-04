def filter_gifts(gifts):
  # Code here
  return filter(gifts, lambda g: !g.contains('#'))

