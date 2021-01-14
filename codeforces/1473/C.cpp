#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	if(n==k){
		for(int i = 1;i <= n;i++){
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	if(k==2){
		cout << 2 << " " << 1 << '\n';
		return;
	}
	for(int i = 1;i < k-(n-k);i++) cout << i << " ";
	cout << k << " ";
	for(int i = k-1;i >= k-(n-k);i--){
		cout << i << " ";
	}
	cout << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}