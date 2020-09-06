#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int pos = 0;
	int ans = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		if(tmp > 0) pos += tmp;
		else ans += (pos+tmp<0 ? abs(pos+tmp) : 0), pos = max((int)0,pos+tmp);	
		//cout << i << " " << tmp << " " << pos << " " << ans << "\n";
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}