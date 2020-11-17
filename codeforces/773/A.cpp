#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y,p,q;
	cin >> x >> y >> p >> q;
	if(p==0) cout << (x==0 ? 0 : -1) << '\n';
	else if(p==q) cout << (x==y ? 0 : -1) << "\n";
	else{
		cout << q*max((y+q-x-p-1)/(q-p),(x+p-1)/p)-y << "\n";
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}