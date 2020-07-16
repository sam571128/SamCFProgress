#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const ll N = 1e5+5;
vector<ll> adj[N];
ll visited[N];
ll cnt1 = 0;
ll cnt2 = 0;


void dfs(ll u, ll c = 0){
	visited[u] = 1;
	if(c) cnt1++;
	else cnt2++;
	for(auto v : adj[u]){
		if(!visited[v]) dfs(v,c^1);
	}
}

int main(){
	fastio
	ll n;
	cin >> n;
	for(ll i = 0;i < n-1;i++){
		ll u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	cout << cnt1*cnt2-(n-1) << "\n";
}