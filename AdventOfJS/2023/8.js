function organizeGifts(gifts) {
  const regexp = /(\d+)([a-z])/g
  let match, result = "";

  while (match = regexp.exec(gifts)) {
    const amount = parseInt(match[1]);
    const letter = match[2];

    const boxes = Math.floor(amount / 10);
    const palets = Math.floor(boxes / 5);
    const bags = amount - boxes * 10;

    result += `[${letter}]`.repeat(palets)
    result += `{${letter}}`.repeat(boxes - palets * 5);
    result += `(${letter.repeat(bags)})`.repeat(bags > 0);
  }

  return result;
}
