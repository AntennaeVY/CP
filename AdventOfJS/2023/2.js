function manufacture(gifts, materials) {
  const can = [];
  const has = {};

  for (const material of materials)
    has[material] = true;

  for (const gift of gifts) {
    const splitted = gift.split("");

    if (splitted.every(v => v in has))
      can.push(gift);
  }

  return can;
}
