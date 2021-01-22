#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7;
vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

int cnt[71], num[71], dp[71][1<<18];

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
	//cout << primes.size() << "\n";
	for(int i = 1;i <= 70;i++){
		int tmp = i;
		for(int j = 0;j < primes.size();j++){
			while(tmp%primes[j]==0) num[i]^=(1<<j), tmp/=primes[j];
		}
	}
	int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}

	dp[0][0] = 1;
	for(int i = 1;i <= 70;i++){
		for(int j = 0;j < (1<<18);j++){
			if(!cnt[i]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i-1][j^num[i]])%MOD * fastpow(2,cnt[i]-1)%MOD;
		}
	}
	cout << (dp[70][0]-1+MOD)%MOD << "\n";
} 