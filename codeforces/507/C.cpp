#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int h,n;
	cin >> h >> n;
	int l = 1;
	int ans = 0;
	for(int i = h;i;i--){
		if((n<=(1ll<<(i-1)))^l) ans += (1ll<<i);
		else ans++;
		if(n > (1ll<<(i-1))) n -= (1ll<<(i-1)), l = 1;
		else l = 0;
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}