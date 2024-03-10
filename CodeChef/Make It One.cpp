#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int l, r;
        cin >> l >> r;
        
        int n = r-l+1;
        vector<int> b(n);
        
        bool can = false;
        
        if (n % 2) {
            for(int i=0; i < n-1; i++) {
                b[i] = l+i+1;
            }
        
            b[n-1] = l;
            
            if (__gcd(l, r) == 1)
                can = true;
                
            for(int i=0; i < n; i++) {
                if (__gcd(l, l+i) == 1 && __gcd(b[i], r) == 1) {
                    swap(b[i], b[n-1]);
                    can = true;
                    
                    break;
                }
            }
            
        } else {
            can = true;
            
            for(int i=0; i < n; i += 2) {
                b[i] = l+i+1;
                b[i+1] = l+i;
            }
        }
       if (can) {        
            for(int i=0; i < n; i++) {
                cout << b[i] << " ";
            }
       } else {
            cout << -1;
        }
        cout << endl;
    }
}
