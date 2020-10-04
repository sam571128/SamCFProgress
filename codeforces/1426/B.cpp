#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	bool ok = false;
	for(int i = 0;i < n;i++){
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		if(b==c){
			ok = true;
		}
	}
	if(m%2) ok = false;
	cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}