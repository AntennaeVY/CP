#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, x;
        cin >> n >> x;
        
        map<int, int> cnt;
        
        for(int i=2; i*i <= x; i++) {
            while(x % i == 0)
                cnt[i]++, x /= i;
        }
        
        if (x != 1)
            cnt[x]++;
            
        long long ans = 0;
        
        for(int i=1; i <= n; i++) {
            long long res = 1;
            
            for(auto [_, k] : cnt) {
                int ways = (binpow(k+1, i) - binpow(k, i) + mod) % mod;
                
                res = (res * ways) % mod;
            }
            
            ans = (ans + res) % mod;
        }
        
        cout << ans << endl;
    }
}
