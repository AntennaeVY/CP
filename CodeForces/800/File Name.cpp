#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int ans=0, x=0;
    
    for(int i=0; i < n; i++) {
        if (s[i] == 'x')
            x++;
        else 
            ans += max(x-2, 0), x = 0;
    }
    
    ans += max(x-2, 0);
    cout << ans << endl;
}