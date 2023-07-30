function isSubsequence(s: string, t: string): boolean {
  let index = 0;

  for (let i = 0; i < t.length; i++) {
    if (index < s.length && s[index] == t[i]) index++;
  }

  return index == s.length;
}
