#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	int arr[a*b], sum = 0;
	for(auto &x : arr) cin >> x;
	int pos = a*b-a/2-1;
	while(b--){
		sum += arr[pos];
		pos -= a/2+1;
	}
	cout << sum << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}