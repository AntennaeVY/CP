#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(auto &ai : a) cin >> ai;
        
        int mn = n;
        
        for(int i=32; i >= 0; i--) {
            int result = 0, cnt = 0;
            
            for(int j=0; j < n; j++) {
                if (a[j] >= (1LL << i)) {
                    cnt++;
                    continue;
                }
                
                result |= a[j];
            }
            
            if (__builtin_popcount(result) == i)
                mn = min(mn, cnt);
        }
        
        cout << mn << endl;
    }

}
