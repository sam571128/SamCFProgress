#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x;
	cin >> n >> x;
	int sum = 0, ans2 = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		ans2 += (tmp+x-1)/x;
		sum += tmp;
	}
	cout << (sum+x-1)/x << " " << ans2 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}