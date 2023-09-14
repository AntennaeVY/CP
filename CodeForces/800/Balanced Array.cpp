#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        if (n % 4 == 2) {
            cout << "NO" << endl;
            continue;
        }
        
        cout << "YES" << endl;
        
        for(int i=1; i <= n/2; i++) {
            cout << 4*i << " ";
        }
        
        for(int i=1; i <= n/2; i++) {
            if (i % 2 == 0)
                cout << 4*i + 1 << " ";
            else
                cout << 4*i - 1 << " ";
        }
        
        cout << endl;
    }

}