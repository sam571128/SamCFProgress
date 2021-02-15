#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt[105] = {};
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		cnt[tmp]++;
	}
	int ans = 0;
	bool ok = 0;
	for(int i = 1;i <= 100;i++){
		if(ok) ans += cnt[i];
		if(cnt[i]) ok = 1;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}