//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,s;
	cin >> n >> s;
	vector<int> arr(n);
	for(int i = 0;i < n;i++) cin >> arr[i];
	int idx = 0;
	for(int i = 0;i < n;i++){
		if(arr[i]>arr[idx]) idx = i;
		s -= arr[i];
		if(s < 0) break;
	}
	if(s>=0) idx = -1;
	cout << idx+1 << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}