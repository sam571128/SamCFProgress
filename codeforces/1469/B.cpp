#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum = 0;
	int ma = 0;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		sum += tmp;
		ma = max(sum,ma);
	}
	sum = 0;
	int ans = ma;
	int m;
	cin >> m;
	for(int i = 0;i < m;i++){
		int tmp;
		cin >> tmp;
		sum += tmp;
		ans = max(ans,sum+ma);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}