function distributeGifts(packOfGifts: string[], reindeers: string[]): number {
  const giftsWeight = packOfGifts.reduce((a, b) => a + b.length, 0);
  const maxWeight = 2 * reindeers.reduce((a, b) => a + b.length, 0);

  return Math.floor(maxWeight / giftsWeight);
}
