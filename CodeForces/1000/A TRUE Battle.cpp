#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t = 1;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    
   	string s;
   	cin >> s;
   	
   	if (s[0] == '1' || s.back() == '1'){
   		cout << "YES" << endl;
   		continue;	
   	}
   	
   	if (s.find("11") != string::npos) {
   		cout << "YES" << endl;
   		continue;
   	}
   	
   	cout << "NO" << endl;

  }
}