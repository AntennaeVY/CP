#include<bits/stdc++.h>
using namespace std;
 
int main() {
    string s;
    cin >> s;
    
    set<char> t(s.begin(), s.end());
    
    if (t.count('H') || t.count('Q') || t.count('9'))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}