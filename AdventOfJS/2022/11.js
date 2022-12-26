function getCompleted(part, total) {
  const [h, m, s] = part.split(":").map(n => parseInt(n));
  const [ht, mt, st] = total.split(":").map(n => parseInt(n));

  const p = 3600 * h + 60 * m + s;
  const t = 3600 * ht + 60 * mt + st;

  const gcd = (a, b) => {
    return b ? gcd(b, a % b) : a;
  }

  return `${p / gcd(p, t)}/${t / gcd(p, t)}`;
}
