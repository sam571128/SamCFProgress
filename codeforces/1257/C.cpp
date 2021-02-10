#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int ans = 1e18;
	int n;
	cin >> n;
	int lst[n+1];
	fill(lst,lst+n+1,-1);
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i++){
		if(~lst[arr[i]]) ans = min(ans,i-lst[arr[i]]+1);
		lst[arr[i]] = i;
	}
	cout << (ans==1e18 ? -1 : ans) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}