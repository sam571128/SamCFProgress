#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5, MOD = 1e9+7;
int cnt[N], fact[N];

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res*n%MOD;
		n = n*n%MOD;
		p>>=1;
	}
	return res;
}

int nCr(int n, int r){
	return fact[n]*fastpow(fact[n-r],MOD-2)%MOD*fastpow(fact[r],MOD-2)%MOD;
}

int dp[8][N];

signed main(){
	fastio
	init();
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}
	for(int i = 1;i < N;i++){
		for(int j = i+i; j < N;j += i){
			cnt[i] += cnt[j];
		}
	}

	for(int i = 1;i < 8;i++){
		for(int j = N-1;j;j--){
			//cout << i << " " << j << "\n";
			dp[i][j] = nCr(cnt[j],i);
			for(int k = j+j;k < N;k+=j){
				dp[i][j] = (dp[i][j]-dp[i][k]+MOD)%MOD;
			}
		}
		if(dp[i][1] > 0){
			cout << i << "\n";
			return 0;
		}
	}
	cout << -1 << "\n";
}