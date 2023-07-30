class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '#') {
        s.erase(s.begin() + max(0, i - 1), s.begin() + i + 1);
        i = max(-1, i - 3);
      }
    }

    for (int i = 0; i < t.size(); i++) {
      if (t[i] == '#') {
        t.erase(t.begin() + max(0, i - 1), t.begin() + i + 1);
        i = max(-1, i - 3);
      }
    }

    return s == t;
  }
};