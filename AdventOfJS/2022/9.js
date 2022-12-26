function countTime(leds) {
  const a = leds.join("").split("1").map(s => s.length);
  return 7 * Math.max(...a, a[0] + a.at(-1));
}
