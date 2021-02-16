#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int now = arr[0];
	int ans = 0;
	for(auto x : arr){
		if(now > x){
			now= (now+1)/2;
			while(now>x) now= (now+1)/2, ans++;
			now = x;
		}else if(now < x){
			now*=2;
			while(now<x) now *= 2, ans++;
			now = x;
		}
	}
	cout << ans << "\n";
}

signed main(){
	//fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}