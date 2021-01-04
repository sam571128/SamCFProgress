#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> v;
	for(int i = 0;i < m;i++){
		int y,x;
		cin >> y >> x;
		v.push_back({x,y});
	}
	sort(v.begin(),v.end());
	bool ok = true;
	if(m%2) ok = false;
	for(int i = 0;i < m;i+=2){
		if(i&&v[i].first==v[i-1].first||((v[i].first+v[i].second)&1)==((v[i+1].first+v[i+1].second)&1)) ok = false;
	}
	cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}