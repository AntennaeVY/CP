class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minSize = 300;
        string prefix = "";

        for(int i=0; i < strs.size(); i++) {
            minSize = min(minSize, (int)strs[i].size());
        }
        
        for(int i=0; i < minSize; i++) {
            bool ok = true;
            char match = strs[0][i];

            for(int j=0; j < strs.size(); j++) {
                if (strs[j][i] != match)
                    ok = false;
            }
        
            if (!ok) break;

            prefix += match;
        }

        return prefix;
    }
};