class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> m;

        for(auto log : logs) {
            int id = log[0], t = log[1];
            
            m[id].insert(t);
        }

        vector<int> uam(k, 0);

        for(auto [id, s] : m) {
            uam[s.size() - 1] += 1;
        }

        return uam;
    }
};