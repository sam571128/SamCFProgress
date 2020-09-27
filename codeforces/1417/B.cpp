#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	unordered_map<int,int> c,cnt;
	int n,t;
	cin >> n >> t;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i++){
		cnt[arr[i]]++;
		if(!c[t-arr[i]])
			c[arr[i]] = 1;
	}
	for(int i = 0;i < n;i++){
		if(arr[i]==t-arr[i]&&cnt[arr[i]]%2==0) cout << (c[arr[i]]^1) << " ";
		else cout << c[arr[i]] << " ";
		cnt[arr[i]]--;
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}