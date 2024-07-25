class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;

        for(auto ch : s)
            cnt += (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');

        return !!cnt;
    }
};