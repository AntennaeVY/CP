function howManyReindeers(reindeerTypes, gifts) {
  reindeerTypes = reindeerTypes.sort(
    (x, y) => y.weightCapacity - x.weightCapacity
  );
  
  return gifts.map(({ country, weight }) => {
    let currentMax = weight;
    let weights = reindeerTypes.filter((x) => x.weightCapacity < currentMax);
    let currentCapacity = weights.reduce(
      (acc, curr) => (acc += curr.weightCapacity),
      0
    );

    let reindeers = weights.map(({ type, weightCapacity }) => {
      let num = (currentMax / currentCapacity) >> 0;
      currentCapacity -= weightCapacity;
      currentMax -= num * weightCapacity;
      return { type, num };
    });
    return { country, reindeers };
  });
}
