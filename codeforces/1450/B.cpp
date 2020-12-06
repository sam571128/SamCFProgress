#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;




void solve(){
	vector<pair<int,int>> v;
	int n,k;
	cin >> n >> k;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	for(int i = 0; i < n;i++){
		bool can = 1;
		for(int j = 0;j < n;j++){
			if(abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second)>k){
				can = false;
			}
		}
		if(can){
			cout << 1 << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}