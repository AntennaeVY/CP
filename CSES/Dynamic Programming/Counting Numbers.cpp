#include<bits/stdc++.h>
using namespace std;

long long dp[21][11][2][2]; 
vector<int> num;

long long solve(int i, int p, bool t, bool lz) {
    if (i == num.size())
        return 1;

    if (dp[i][p][t][lz] != -1)
        return dp[i][p][t][lz];
    
    long long ans = 0;
    int limit = t ? num[i] : 9;
    
    for(int d=0; d <= limit; d++) {
        if (!lz && d == p) continue;
            
        bool new_lz = lz && (d == 0);
        int new_p = new_lz ? 10 : d; 
        bool new_t = t && (d == limit);
        
        ans += solve(i+1, new_p, new_t, new_lz);
    }
    
    return dp[i][p][t][lz] = ans;
}

long long calc(long long n) {
    if (n < 0) return 0;
    if (n == 0) return 1; 
    
    num.clear();
    while (n > 0) {
        num.push_back(n % 10);
        n /= 10;
    }
    
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    
    return solve(0, 10, true, true);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a, b;
    cin >> a >> b;
    
    cout << calc(b) - calc(a - 1) << endl;
}