class Solution {
public:
    string minWindow(string s, string t) {
        if (size(t) > size(s))
            return "";
        
        map<char, int> x, y;
        for(char c : t)
            x[c]++;

        set<char> z;
        int min_length = 1e9;
        string ans = "";

        int l=0;
        for(int r=0; r < size(s); r++) {
            y[s[r]]++;

            if (x.find(s[r]) != x.end() && y[s[r]] >= x[s[r]])
                z.insert(s[r]);

            while(z.size() == x.size()) {
                if (x.find(s[l]) != x.end() && y[s[l]] - 1 < x[s[l]])
                    break;

                y[s[l]]--;
                l++;
            }

            if (z.size() == x.size() && r-l+1 < min_length) {
                min_length = r-l+1;
                ans = s.substr(l, r-l+1);
            }
        }

        return ans;
    }
};