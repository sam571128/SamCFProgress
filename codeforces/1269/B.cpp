#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int a[n], b[n];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	sort(a,a+n);
	sort(b,b+n);
	int ans = 1e18;
	for(int i = 0;i < n;i++){
		int tmp = 1e18;
		for(int j = 0;j < n;j++){
			if(tmp==1e18) tmp = (b[(j+i)%n]-a[j]+m)%m;
			//cout << j << " " << i << " " << (b[(j+i)%n]-a[j]+m)%m << " " << tmp << "\n";
			if((b[(j+i)%n]-a[j]+m)%m!=tmp) goto notans;
		}
		ans = min(ans,tmp);
		notans:;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}