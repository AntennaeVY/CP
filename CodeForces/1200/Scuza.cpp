#include<bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin >> t;
    
    while(t--) {
        int n,q;
        cin >> n >> q;
        
        vector<int> a(n+2, 0);
        vector<long long> b(n+2, 0);
        
        for(int i=1; i <= n; i++) {
            int x;
            cin >> x;
            
            a[i] = max(a[i-1], x);
            b[i] = b[i-1] + x;
        }
        
        a[n+1] = 2e9;
        b[n+1] = 9e18;
        
        for(int i=0; i < q; i++) {
            int k;
            cin >> k;
            
            int l=0, r=n+1;
            
            while(l+1 < r) {
                long long mid = l + (r-l)/2;
                
                if (a[mid] <= k)
                    l = mid;
                else 
                    r = mid;
            }
            
            cout << b[l] << " ";
        }
        
        cout << endl;
    }
}