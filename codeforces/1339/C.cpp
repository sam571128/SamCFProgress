#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	ll ma = -1e18;
	ll last = 0;
	ll inc = 0;
	for(ll i = 0, tmp;i < n;i++){
		cin >> tmp;
		inc = max(ma-tmp,inc);
		ma = max(tmp, ma);
		last = tmp;
	}
	ll sum = 0, ans = 0;
	while(sum < inc){
		sum += pow(2,ans);
		ans++;
	}
	cout << ans << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}