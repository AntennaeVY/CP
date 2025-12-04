#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long pw(long long b, long long e) {
    long long res = 1;
    b %= MOD;
    while (e > 0) {
        if (e % 2 == 1) res = (res * b) % MOD;
        b = (b * b) % MOD;
        e /= 2;
    }
    return res;
}

long long inv(long long n) {
    return pw(n, MOD - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;

    vector<long long> t(q);
    vector<long long> s(q), m(q);
    
    m[0] = 1; 
    s[0] = 0; 
    
    for(int i=0; i < q; i++) {
        int c;
        cin >> c;
        
        if (i > 0) {
            s[i] = s[i-1];
            m[i] = m[i-1];
        }
        
        if (c == 1) {
            int x;
            cin >> x;
            t[i] = x; 
        } else if (c == 2) {
            long long x;
            cin >> x;
            
            s[i] = (s[i] + x) % MOD;
            if (s[i] < 0) s[i] += MOD; 

        } else if (c == 3) {
            long long pa, qb;
            cin >> pa >> qb;
            
            long long f = (pa * inv(qb)) % MOD;
            
            m[i] = (m[i] * f) % MOD;
            s[i] = (s[i] * f) % MOD;
            
            if (m[i] < 0) m[i] += MOD;
            if (s[i] < 0) s[i] += MOD;

        } else if (c == 4) {
            int j;
            cin >> j;
            j--;
            
            long long val = (t[j] - s[j]) % MOD;
            if (val < 0) val += MOD;
            
            long long r = (m[i] * inv(m[j])) % MOD;
            
            val = (val * r) % MOD;
            val = (val + s[i]) % MOD;
            
            cout << val << "\n";
        }
    }
}