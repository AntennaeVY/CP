function getIndexsForPalindrome(word) {
  const n = word.length;

  const prefix = word.slice(0, n / 2);
  const suffix = word
    .slice(n / 2 + (n % 2))
    .split("")
    .reverse()
    .join("");
  const wildcard = n % 2 ? word[(n / 2) | 0] : "*";

  const bad = [];

  for (const i of prefix.split("").keys()) {
    if (prefix[i] != suffix[i]) bad.push(i);
  }

  if (bad.length == 0) return [];

  if (bad.length > 2) return null;

  const ans = [];

  if (bad.length == 2) {
    if (
		prefix[bad[0]] == suffix[bad[1]] && 
		prefix[bad[1]] == suffix[bad[0]]
	) {
      ans.push(bad[0], bad[1]);
    } else if (
      prefix[bad[0]] == prefix[bad[1]] &&
      suffix[bad[0]] == suffix[bad[1]]
    ) {
      ans.push(bad[0], n - bad[1] - 1);
    } else return null;
  } else if (bad.length == 1) {
    if (
		prefix[bad[0]] != wildcard && 
		wildcard == suffix[bad[0]]
	) {
      ans.push(bad[0], (n / 2) | 0);
    } else if (
		suffix[bad[0]] != wildcard && 
		wildcard == prefix[bad[0]]
	) {
      ans.push((n / 2) | 0, n - bad[0] - 1);
    } else return null;
  }

  return ans;
}

