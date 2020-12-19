#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int mi = 1e18;
	int arr[n][m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> arr[i][j];
			mi = min(mi,arr[i][j]);
		}
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			ans += arr[i][j]-mi;
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