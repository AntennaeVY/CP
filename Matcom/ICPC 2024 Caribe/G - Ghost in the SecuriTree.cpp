#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;
using __gnu_pbds::tree;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree_order_statistics_node_update;
using __gnu_pbds::null_type;

// _GLIBCXX_DEBUG must not be defined otherwise some internal check will fail
#undef _GLIBCXX_DEBUG

template <typename K, typename V, typename Comp = less<K>>
using indexed_map = tree<K, V, Comp, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename Comp = less<K>>
using indexed_set = indexed_map<K, null_type, Comp>;

// ¡¡IMPORTANT!! (for using less_equals<K>)
// using less_equals<K> makes lower_bound works as upper_bound and vice-versa
// for erase use: any.erase(any.find_by_order(any.order_of_key(val)));
// don't use .find() because it will always return .end()
template <typename K, typename V, typename Comp = less_equal<K>>
using indexed_multimap = indexed_map<K, V, Comp>;

template <typename K, typename Comp = less_equal<K>>
using indexed_multiset = indexed_map<K, null_type, Comp>;

int main() {
  int n, q, r;
  cin >> n >> q >> r;
  
  vector<vector<int>> g(n+10);
  
  for(int i=0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  vector<int> ans(q);
  vector<vector<pair<int,int>>> ops(n+1);
  
  for(int i=0; i < q; i++) {
    int u, k;
    cin >> u >> k;
    
    ops[u].push_back({k, i});
  }
  
  indexed_set<int> st;
  
  auto dfs = [&](auto &&self, int u, int p = -1) -> void {
    st.insert(u);
    
    if (ops[u].size()) {
      for(auto [k, i] : ops[u])
          ans[i] = *st.find_by_order(k-1);
    }
    
    for(auto &v : g[u])
      if(v != p)
        self(self, v, u);
        
    st.erase(st.find_by_order(st.order_of_key(u)));
  };
  
  dfs(dfs, r);
  
  for(int i=0; i < q; i++) {
  	cout << ans[i] << endl;
  }
}
