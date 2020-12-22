#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};

const int N = 1e5+5;

gp_hash_table<int,int,chash> dsu[N];

int find(int idx, int u){
  return dsu[idx][u]==u||dsu[idx][u]==0 ? u : find(idx,dsu[idx][u]);
}

void unite(int idx, int u, int v){
  u = find(idx,u), v = find(idx,v);
  if(u==v) return;
  dsu[idx][u] = v;
}

set<int> adj[N];
map<pair<int,int>,int> ans;

signed main(){
  fastio
  int n,m;
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    int u,v,c;
    cin >> u >> v >> c;
    unite(c,u,v);
    adj[u].insert(c);
    adj[v].insert(c);
  }
  int q;
  cin >> q;
  while(q--){
    int u,v;
    cin >> u >> v;
    if(adj[u].size() > adj[v].size()) swap(u,v);
    if(ans.count({u,v})){
      cout << ans[{u,v}] << "\n";
      continue;
    }
    int tmp = 0;
    for(auto c : adj[u]){
      tmp += (find(c,u)==find(c,v));
    }
    ans[{u,v}] = tmp;
    cout << tmp << "\n";  
  }
}