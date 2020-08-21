#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,k;
	cin >> n >> k;
	if(n < k){
		cout << k-n << "\n";
	}else{
		if(n%2!=k%2){
			cout << 1 << "\n";
		}else{
			cout << 0 << "\n";
		}
	}
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}