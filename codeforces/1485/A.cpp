#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	int ans = INT_MAX;
	for(int i = 0;;i++,b++){
		if(b==1) continue;
		if(i >= ans) break;
		int now = i;
		int tmp = a;
		while(tmp!=0) tmp/=b, now++;
		ans = min(now,ans);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}