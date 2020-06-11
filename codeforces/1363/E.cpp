#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const ll N = 2e5+5;
ll n, a[N], b[N], c[N], cost;
vector<ll> adj[N];

pair<ll,ll> dfs(ll u, ll par, ll mi){
	pair<ll,ll> p = {0,0};
	if(b[u]!=c[u]){
		if(b[u]) p.first++;
		else p.second++;
	}
	for(ll v : adj[u]){
		if(v == par) continue;
		auto d = dfs(v, u , min(mi, a[u]));
		p.first += d.first;
		p.second += d.second;
	}
	if(a[u] < mi){
		ll shuff = min(p.first, p.second);
		cost += 2 * shuff * a[u];
		p.first -= shuff;
		p.second -= shuff;
	}
	return p;
}

int main(){
	fastio
	cin >> n;
	for(ll i = 1;i <= n;i++)
		cin >> a[i] >> b[i] >> c[i];
	for(ll i = 0;i < n-1;i++){
		ll u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	pair<ll,ll> ans = dfs(1 , 0 , 2e9);
	if(ans.first||ans.second){
		cout << -1 << "\n";
	}else{
		cout << cost << "\n";
	}
}