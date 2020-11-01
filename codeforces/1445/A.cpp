#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,x;
	cin >> n >> x;
	int a[n],b[n];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	sort(a,a+n);
	sort(b,b+n,greater<int>());
	for(int i = 0;i < n;i++){
		if(a[i]+b[i] > x){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}