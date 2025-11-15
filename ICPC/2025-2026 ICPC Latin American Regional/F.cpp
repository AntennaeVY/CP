#include<bits/stdc++.h>
using namespace std; 

int main() {
    string s;
    cin >> s;

    map<long long, int> ans;
    
    int c = 0;
    while(s.size() > 16) {
        int x = s.back() - '0' + c;

        ans[2] += 1;
        ans[5] += 1;

        s.pop_back();
    }

    long long n = stoll(s);

    for(long long i=2; i*i <= n; i++) {
        int m = 0;
        
        while(n % i == 0) {
            n /= i;
            m++;
        }

        if (m)
            ans[i] += m;
    }

    if (n != 1)
        ans[n] += 1;

    cout << ans.size() << "\n";

    for(auto &[p,e] : ans)
        cout << p << " " << e << "\n";
}