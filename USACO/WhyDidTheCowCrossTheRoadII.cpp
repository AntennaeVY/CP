#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("circlecross.in");
  ofstream fout("circlecross.out");

  string path;
  fin >> path;

  map<int, int> start, end;

  for (int i = 0; i < 52; i++) {
    if (start[path[i] - 'A'] == 0)
      start[path[i] - 'A'] = i + 1;
    else
      end[path[i] - 'A'] = i + 1;
  }

  int ans = 0;

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (j == i) continue;
 		
 	  if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j])
 	  	ans++;
    }
  }
  
  fout << ans << endl;
}