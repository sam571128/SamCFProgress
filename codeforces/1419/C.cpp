#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x;
	cin >> n >> x;
	int sum = 0;
	int arr[n];
	bool ok = true;
	int cnt = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		if(arr[i]!=x) ok = false, cnt++;
	}
	int change = 0;
	for(int i = 0;i < n;i++){
		change += x-arr[i];
	}
	if(ok) cout << 0 << "\n";
	else if(change==0||(n-cnt)>=1) cout << 1 << "\n";
	else cout << 2 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}