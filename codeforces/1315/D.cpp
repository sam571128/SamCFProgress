#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


map<int,int> m;

int find(int u){
	return (m[u]==0 ? u : m[u] = find(m[u]));
}

void unite(int x, int y){
	m[find(x)] = find(y);
}

void solve(){
	//Solved => Use DSU to store the number we should move the element to
	int n;
	cin >> n;
	int a[n+1], t[n+1];
	priority_queue<pair<int,int>> pq;
	for(int i = 1; i <= n;i++) cin >> a[i];
	for(int i = 1; i <= n;i++) cin >> t[i];	
	for(int i = 1; i <= n;i++) pq.push({t[i],a[i]});
	int ans = 0;
	while(!pq.empty()){
		auto x = pq.top(); pq.pop();
		if(find(x.second) == x.second){
			unite(x.second,x.second+1);
		}else{
			int nx = find(x.second);
			ans += (nx-x.second)*x.first;
			unite(nx,nx+1);
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}