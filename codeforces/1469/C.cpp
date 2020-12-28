#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	int h[n];
	for(auto &x : h) cin >> x;
	pair<int,int> can[n];
	can[0] = {h[0],h[0] + k};
	can[n-1] = {h[n-1],h[n-1]+k};
	//cout << 0 << " " << can[0].first << " " << can[0].second << "\n";
	for(int i = 1;i < n-1;i++){
		can[i] = {min(h[i]+k-1,max(h[i],can[i-1].first+1-k)),min(h[i]+k-1+k,can[i-1].second-1+k)};
		//cout << i << " " << can[i].first << " " << can[i].second << "\n";
	}
	for(int i = 1;i < n;i++){
		if(can[i-1].first >= can[i].second||can[i-1].second <= can[i].first){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}