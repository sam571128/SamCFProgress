#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,q,k;
	cin >> n >> q >> k;
	int arr[n], num[n] = {}, pref[n+1] = {};
	for(auto &x : arr) cin >> x;
	if(n!=1){
		for(int i = 1;i < n-1;i++){
			num[i] = arr[i+1]-arr[i-1]-1-1;
		}
		for(int i = 0;i < n;i++) pref[i+1] = num[i] + pref[i];
		while(q--){
			int l,r;
			cin >> l >> r;
			l--,r--;
			if(l==r){
				cout << k-1 << "\n";
				continue;
			}
			int ans = 0;
			ans += arr[l+1]-1-1;
			ans += k-arr[r-1]-1;
			ans += pref[r]-pref[l+1];
			cout << ans << "\n";
		}
	}else{
		while(q--){
			int l,r;
			cin >> l >> r;
			cout << k-1 << "\n";
		}
	}
}