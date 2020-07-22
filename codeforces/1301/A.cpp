#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	string a,b,c;
	cin >> a >> b >> c;
	bool ok = true;
	for(int i = 0;i < a.size();i++){
		if(a[i]!=c[i]&&b[i]!=c[i]){
			ok = false;
			break;
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}