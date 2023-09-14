#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
    
        cout << (a + (c+1)/2 <= b + c/2 ? "Second" : "First") << endl;        
    }
   
}