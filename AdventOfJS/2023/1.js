function findFirstRepeated(gifts) {
  const seen = {};

  for(let gift of gifts) {
    if (seen[gift])
      return gift;

    seen[gift] = true;
  }

  return -1;
}

