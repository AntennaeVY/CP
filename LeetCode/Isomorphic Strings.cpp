class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    map<char, char> m, n;

    for (int i{}; i < s.size(); i++) {
      if (m.count(s[i]) && m[s[i]] != t[i] || n.count(t[i]) && n[t[i]] != s[i])
        return false;
      else {
        m[s[i]] = t[i];
        n[t[i]] = s[i];
      }
    }

    return true;
  }
};