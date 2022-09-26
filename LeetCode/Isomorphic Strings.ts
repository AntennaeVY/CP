function isIsomorphic(s: string, t: string): boolean {
  const mapS_T:{[key: string]: string} = {}, mapT_S:{[key: string]: string} = {};

  for (let i = 0; i < s.length; i++) {
    if (
        mapS_T[s[i]] !== undefined && mapS_T[s[i]] !== t[i] 
        || mapT_S[t[i]] !== undefined && mapT_S[t[i]] !== s[i]
    )
      return false;
    else {
      mapS_T[s[i]] = t[i];
      mapT_S[t[i]] = s[i];
    }
  }

  return true;
};