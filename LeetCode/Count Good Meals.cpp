class Solution {
public:
    int countPairs(vector<int>& a) {
        map<int, int> m;
        
        int mod = 1e9 + 7;
        long long ans = 0;

        for(auto x : a) {
            for(int i=0; i < 22; i++) {
                if (m.find((1 << i) - x) != m.end())
                    ans += m[(1 << i) - x];
            }

            m[x]++;
        }

        return ans % mod;
    }
};
