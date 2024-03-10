class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> cnt1, cnt2;

        for(char c : s1) cnt1[c]++;   

        bool can = false;

        int l=0;
        for(int r=0; r < s2.size(); r++) {
            cnt2[s2[r]]++;

            while(r-l+1 > s1.size()) {
                cnt2[s2[l]]--;

                if (cnt2[s2[l]] == 0)
                    cnt2.erase(s2[l]);
                
                l++;
            }

            if (r-l+1 == s1.size()) 
                can |= (cnt1 == cnt2);
        }

        return can;
    }
};