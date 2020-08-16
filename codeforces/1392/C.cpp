#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int ans = 0, lst = 0;
	while(n--){
		int tt;
		cin >> tt;
		if(tt < lst) ans += lst-tt;
		lst = tt;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}