#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e3+5, MOD = 998244353;
int fact[N];

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		p>>=1;
	}
	return res;
}

int nCr(int n, int r){
	if(n < r||r < 0) return 0;
	return fact[n]*fastpow(fact[n-r],MOD-2)%MOD*fastpow(fact[r],MOD-2)%MOD;
}

signed main(){
	fastio
	init();
	int n;
	cin >> n;
	int arr[n], dp[n] = {};
	int ans = 0;
	for(auto &x : arr) cin >> x;
	for(int i = n-1;~i;i--){
		if(i+arr[i]>=n||arr[i] <= 0) continue;
		dp[i] = nCr(n-i-1,arr[i]);
		for(int j = arr[i]+i+1; j < n;j++){
			dp[i] = (dp[i]+nCr(j-i-1,arr[i])*dp[j]%MOD)%MOD;
		}
	}
	for(int i = 0;i < n;i++) ans = (ans + dp[i])%MOD;
	cout << ans << "\n";
}