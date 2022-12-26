function checkStepNumbers(systemNames, stepNumbers) {
  let ans = true;
  const map = new Map([...new Set(systemNames)].map(c => [c,-1]));

  systemNames.map((c, i) => {
    ans = ans && map.get(c) < stepNumbers[i];

    map.set(c, stepNumbers[i]);
  });

  return ans;
}
