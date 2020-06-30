#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a[3];
	for(auto &x : a) cin >> x;
	ll ans = 0;
	sort(a,a+3);
	for(int i = 1;i <= 2;i++){
		if(a[i] > a[i-1]) a[i]--;
	}
	for(int i = 0;i < 2;i++){
		ans += a[i+1]-a[i];
	}
	ans += a[2]-a[0];
	cout << ans - (ans >= 2 ? 2 : 0) << "\n";
}

int main(){
	fastio
	int q;
	cin >> q;
	while(q--) solve();
}