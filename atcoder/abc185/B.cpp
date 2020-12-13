#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m,t;
	cin >> n >> m >> t;
	int now = 0, nowb = n;
	bool ok = true;
	while(m--){
		int a,b;
		cin >> a >> b;
		nowb -= (a-now);
		if(nowb <= 0){
			ok = false;
		}
		nowb = min(nowb+b-a,n);
		now = b;
	}
	nowb -= (t-now);
	if(nowb <= 0){
		ok = false;
	}
	cout << (ok ? "Yes\n" : "No\n");
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}