#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int x;
        cin >> x;
        
        if (__builtin_popcount(x) == 1) {
            cout << 0 << endl;
            continue;
        }
        
        cout << 2*x - (1 << (__lg(x) + 1)) << endl;
    }

}
