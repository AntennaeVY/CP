#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    long long n, k;
    cin >> n >> k;

    vector<long long> r(n), c(n);
    for(int i=0; i < n; i++) {
        cin >> r[i] >> c[i];
    }

    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    long long U=r[0], D=r[0], L=c[0], R=c[0];

    for(int i=0; i < n; i++) {
        U = max(U, r[i]);
        D = min(D, r[i]);
        L = min(L, c[i]);
        R = max(R, c[i]);
    }

    long long ans = abs((U-D+1) * (R-L+1));

    for(int i=0; i < n; i++) {
        int du, dd, dl, dr;
        
        long long a = abs(U-D+1);
        long long b = abs(R-L+1);

        du = abs(U+1 - r[i]);
        dd = abs(D-1 - r[i]);
        dl = abs(L-1 - c[i]);
        dr = abs(R+1 - c[i]);

        // UL
            ans = max(ans, abs((a + max(0LL, k - du + 1)) * (b + max(0LL, k - dl + 1))));
        
    
        // UR
            ans = max(ans, abs((a + max(0LL, k - du + 1)) * (b + max(0LL, k - dr + 1))));
        

        // DR
            ans = max(ans, abs((a + max(0LL, k - dd + 1)) * (b + max(0LL, k - dr + 1))));


        // DL
            ans = max(ans, abs((a + max(0LL, k - dd + 1)) * (b + max(0LL, k - dl + 1))));
        
    }
    
    long long dx = abs(U - D + 1);
    long long dy = abs(R - L + 1);
    long long k_sim = k;
    while (k_sim--) {
        if (dx < dy) dx++;
        else dy++;
    }
    ans = max(ans, dx * dy);

    cout << ans << "\n";
}