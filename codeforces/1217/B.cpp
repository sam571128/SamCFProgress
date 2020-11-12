#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x;
	cin >> n >> x;
	int mx = 0, mx2 = 0;
	for(int i = 0, x, y;i < n;i++){
		cin >> x >> y;
		mx = max(x,mx);
		mx2 = max(mx2, x-y);
	}
	if(x <= mx) cout << 1 << "\n";
	else if(mx2 == 0) cout << -1 << "\n";
	else{
		cout << (x-mx+mx2-1)/mx2+1 << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}