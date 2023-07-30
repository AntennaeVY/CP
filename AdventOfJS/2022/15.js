function decorateTree(base) {
  const dict = {
    "PP": "P",
    "BB": "B",
    "RR": "R",
    "BP": "R",
    "PB": "R",
    "BR": "P",
    "RB": "P",
    "PR": "B",
    "RP": "B"
  }

  return base.split(' ').slice(1).reduce((p, _, i) => {
    const q = p.at(-1).slice(0, -1).trim().split(' ')
    const r = q.map((_, j) => dict[p.at(-1).replace(/\s/g, '').slice(j, j + 2)])

    return p.concat(r.join(" "));
  }, [base]).reverse();
}
