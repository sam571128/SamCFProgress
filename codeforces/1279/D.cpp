//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353;

const int N = 1e6+5;
int sum[N];

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n)%MOD;
		n = (n*n)%MOD;
		p>>=1;
	}
	return res;
}

int inv(int val){
	return fastpow(val,MOD-2)%MOD;
}

signed main(){
	fastio
	int n;
	cin >> n;
	map<int,int> m;
	for(int i = 0, cnt;	i < n;i++){
		cin >> cnt;
		for(int j = 0;j < cnt;j++){
			int x;
			cin >> x;
			m[x]++;
			sum[x] = (sum[x]+inv(cnt))%MOD;
		}
	}
	int ans = 0;
	for(int i = 0;i < N;i++) ans = (ans+m[i]*sum[i]%MOD)%MOD;
	cout << ans*inv(n)%MOD*inv(n)%MOD << "\n";
}