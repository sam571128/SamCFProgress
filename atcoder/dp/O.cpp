#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
#include <bits/extc++.h>


using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(x,m,n) for(int x = m; x < n;x++)
#define repp(x,m,n) for(int x = m; x <= n;x++)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update, ordered_set>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//find_by_order(), order_of_key();
#define MOD 1000000007
void solve();


int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}


signed main(){
	fastio
	int t = 1;
	//cin >> t;
	rep(i,0,t) solve();
}

void solve(){
	int n;
	cin >> n;
	int grid[n][n];
	rep(i,0,n) rep(j,0,n) cin >> grid[i][j];
	vector<int> dp(1<<n);
	dp[0] = 1;
	for(int j = 0;j < 1<<n;j++){
		int i = __builtin_popcount(j);
		for(int k = 0;k < n;k++){
			if(grid[i][k]&&!(j&(1<<k))) dp[j^(1<<k)] = (dp[j^(1<<k)] + dp[j])%MOD; 
		}
	}
	
	cout << dp[(1<<n)-1] << "\n";
}