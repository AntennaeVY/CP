class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string t = to_string(num);

        sort(t.rbegin(), t.rend());

        for(int i=0; i < s.size(); i++) {
            if (s[i] == t[i])
                continue;

            swap(s[i], s[s.find_last_of(t[i])]);
            break;
        }

        return stoi(s);
    }
};