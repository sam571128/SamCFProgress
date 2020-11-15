#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int cntn = 0, mi = INT_MAX, ans = 0;
	for(int i = 0;i < n;i++) for(int j = 0, tmp;j < m;j++){
		cin >> tmp;
		mi = min(mi,abs(tmp));
		ans += abs(tmp);
		if(tmp < 0) cntn++;
	}
	if(cntn%2) cout << ans - 2*mi << "\n";
	else cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}