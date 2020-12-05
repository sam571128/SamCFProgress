#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int x,y;
	cin >> x >> y;
	map<int,int> m;
	for(int i = 0, tmp;i < x;i++){
		cin >> tmp;
		m[tmp] = 1;
	}
	int ans = 0;
	for(int i = 0, tmp;i < y;i++){
		cin >> tmp;
		ans += m[tmp];
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}