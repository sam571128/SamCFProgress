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
#define MOD 998244353
void solve();

const int N = 1e6+5;
int fact[N];

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++){
		fact[i] = fact[i-1] * i % MOD;
	}
}

int nCr(int n, int r){
	return fact[n]*fastpow(fact[r],MOD-2)%MOD*fastpow(fact[n-r],MOD-2)%MOD;
}

signed main(){
	fastio
	init();
	int t = 1;
	//cin >> t;
	rep(i,0,t) solve();
}

void solve(){
	int n;
	cin >> n;
	n*=2;
	int arr[n];
	for(auto &x : arr) cin >> x;
	sort(arr,arr+n);
	int sum1 = 0, sum2 = 0;
	for(int i = 0;i < n;i++){
		if(i < n/2) sum1 = (sum1+arr[i])%MOD;
		else sum2 = (sum2+arr[i])%MOD;
	}
	n/=2;
	cout << ((sum2-sum1)*nCr(2*n,n)%MOD+MOD)%MOD << "\n";
}