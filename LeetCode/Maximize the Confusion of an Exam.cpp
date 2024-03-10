class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int cnt[2];

        int ans = 0;

        int l=0;
        for(int r=0; r < n; r++) {
            cnt[s[r] == 'T']++;

            while(cnt[0] > k && cnt[1] > k) {
                cnt[s[l] == 'T']--;
                l++;              
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};