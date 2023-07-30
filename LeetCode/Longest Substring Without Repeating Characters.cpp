class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int l=0, ans = 0;

        for(int r=0; r < s.size(); r++) {
            m[s[r]]++;

            while(m[s[r]] > 1)
                m[s[l++]]--;

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};