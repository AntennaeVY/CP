function sortPeople(names: string[], heights: number[]): string[] {
  return names
    .map((name, i) => ({ name, h: heights[i] }))
    .sort((a, b) => b.h - a.h)
    .map(({ name }) => name);
}
