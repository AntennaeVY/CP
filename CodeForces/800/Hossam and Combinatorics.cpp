#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int mn = INT_MAX, mx = 0;
        map<int, int> m;
        vector<int> a(n);
        
        for(int i=0; i < n; i++) {
            cin >> a[i];
            m[a[i]]++;
            
            mn = min(a[i], mn);
            mx = max(a[i], mx);
        }
        
        long long ans = 0;
        
        for(int i=0 ; i < n; i++) {
            if (mx - mn == 0) {
                ans += min(0, m[a[i]] - 1);
                continue;
            }
    
            ans += m[a[i]-(mx-mn)];
            ans += m[mx-mn+a[i]];
        }
        
        cout << ans << endl;
    }
}
