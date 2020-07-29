#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int nC2(int n){
	return n*(n-1)/2;
}

void solve(){
	int n,k,w;
	cin >> n >> k >> w;
	w = w/__gcd(k-1,w);
	int tmp = min(n,k);
	cout << nC2(tmp/w+1)*(tmp%w) + (w-tmp%w)*nC2(tmp/w) << "\n";
}

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}