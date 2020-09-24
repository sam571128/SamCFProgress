#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
//1 3 2 => 3
void solve(){
	int n,q;
	cin >> n >> q;
	int arr[n+2] = {}, ans = 0;
	for(int i = 1;i <= n;i++) cin >> arr[i];
	for(int i = 1;i <= n;i++){
		ans += max((int)0,arr[i]-arr[i-1]);
	}
	cout << ans << "\n";
	while(q--){
		int l,r;
		cin >> l >> r;
		if(l==r){
			cout << ans << "\n";
			continue;
		}
		ans -= max((int)0,arr[r+1]-arr[r]);
		ans -= max((int)0,arr[r]-arr[r-1]);
		if(r!=l+1)ans -= max((int)0,arr[l+1]-arr[l]);
		ans -= max((int)0,arr[l]-arr[l-1]);
		swap(arr[r],arr[l]);
		ans += max((int)0,arr[r+1]-arr[r]);
		ans += max((int)0,arr[r]-arr[r-1]);
		if(r!=l+1)ans += max((int)0,arr[l+1]-arr[l]);
		ans += max((int)0,arr[l]-arr[l-1]);
		cout << ans << "\n";
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}