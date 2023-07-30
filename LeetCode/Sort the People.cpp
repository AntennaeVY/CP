class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    map<int, string> m;
    vector<string> sol;

    for (int i = 0; i < names.size(); i++) {
      m[heights[i]] = names[i];
    }

    for (auto it = m.rbegin(); it != m.rend(); it = next(it)) {
      sol.push_back(it->second);
    }

    return sol;
  }
};