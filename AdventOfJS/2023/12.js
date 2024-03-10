function checkIsValidCopy(original, copy) {
  let isValid = true;

  const degraded = ["#", "+", ":", ".", " "];

  for(const i of original.split("").keys()) {
    const a = original[i], b = copy[i];
    
    if (a == b || b == a.toLowerCase())
      continue;
    
    const index = degraded.indexOf(a);
    const subdegraded = degraded.slice(Math.max(index, 0));

    isValid &&= subdegraded.includes(b);
  }

  return isValid
}
