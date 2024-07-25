#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        for(auto &ai : a) cin >> ai;
        
        long long acc = 0; 
        int ans = 0;
        
        for(int i=0; i < n; i++) {
            acc += max(0, a[i] - x);
            
            ans += a[i] >= x;
        }
        
        sort(a.rbegin(), a.rend());
        
        for(int i=0; i < n; i++) {
            if (a[i] >= x)
                continue;
                
            int need = x - a[i];
            
            if (acc < need)
                break;
                
            acc -= need;
            ans++;
        }
        
        cout << ans << endl;
    }
}
