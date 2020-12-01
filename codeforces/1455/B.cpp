#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int tmp = 0, now = 0;
	while(now < n){
		now += tmp++;
	}
	if(now-1==n) tmp++;
	cout << tmp-1 << "\n";

}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}