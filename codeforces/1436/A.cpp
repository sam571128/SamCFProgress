#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n,m;
	cin >> n >> m;
	int sum = 0;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		sum += tmp;
	}
	cout << (sum==m ? "YES\n" : "NO\n");
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}