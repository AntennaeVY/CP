#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> w(n);
        for(auto &wi : w) cin >> wi;
        
        sort(w.rbegin(), w.rend());
        
        int ans = 0;
        
        for(int i=0 ; i < n; i++) {
            ans = max(ans, w[i] * (i+1));
        }
        
        cout << ans << endl;
    }

}
