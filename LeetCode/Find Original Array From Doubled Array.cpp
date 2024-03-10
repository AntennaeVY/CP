class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, set<int>> m;
        vector<bool> processed(changed.size(), false);
        vector<int> ans;

        sort(changed.begin(), changed.end());

        for(int i=0; i < changed.size(); i++) {
            m[changed[i]].insert(i);
        }

        for(int i=0; i < changed.size(); i++) {
            if (processed[i])
                continue;

            m[changed[i]].erase(i);
            processed[i] = true;

            if (m[2*changed[i]].size() == 0)
                return {};

            int idx = *(m[2*changed[i]].begin());

            m[2*changed[i]].erase(idx);
            processed[idx] = true;

            ans.push_back(changed[i]);
        }

        return ans;
    }
};