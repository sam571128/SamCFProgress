#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	while(n--){
		int x,y;
		cin >> x >> y;
		if(x>0) cnt1++;
		else cnt2++;
	}
	if(min(cnt1,cnt2)<2) cout << "YES\n";
	else cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}