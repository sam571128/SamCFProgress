#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(LLONG_MAX/res < n){
			return 1e13;
		}
		if(p&1) res = (res * n);
		if(LLONG_MAX/n < n){
			return 1e13;
		}
		n = (n * n);
		p>>=1;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	sort(a,a+n);
	int ans = LLONG_MAX;
	for(int i = 1;i <= 1e9;i++){
		int tmp = 0;
		//cout << i << "\n";
		if(fastpow(i,n-1)==1e13) break;
		for(int j = 0;j < n;j++){
			//cout << fastpow(i,j) << " ";
			tmp += abs(fastpow(i,j)-a[j]);
		}
		//cout << "\n";
		ans = min(abs(tmp),ans);
	}
	cout << ans << "\n";
}

signed main(){
	//fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}