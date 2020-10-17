#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y,a,b;
	int ans = 0, cnt = 0;
	cin >> x >> y >> a >> b;
	while(x < y){
		ans = max((y-x-1)/b+cnt,ans);
		if(LLONG_MAX/x < a) break;
		cnt++, x*=a;
	}
	cout << ans << "\n";
}	

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}
