#pragma optimize(3)
#pragma optimize("unroll-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 1e9+7, N = 1e6+5;

int fact[N], cnt[N], phi[N], has[N], nCk[N];
vector<int> d[N];

int n,k,q;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n %MOD;
		n = n*n%MOD;
		p>>=1;
	}
	return res;
}

int nCr(int n, int r){
	if(n < r) return 0;
	return fact[n]*fastpow(fact[r],MOD-2)%MOD*fastpow(fact[n-r],MOD-2)%MOD;
}

void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;

	//Initialize Euler Totient
	iota(phi,phi+N,0);
	for(int i = 1;i < N;i++){
		if(has[i]) d[i].push_back(i);
		for(int j = i+i;j < N;j+=i){
			if(has[j]) d[j].push_back(i);
			phi[j] -= phi[i];
		}
	}
	for(int i = 1;i < N;i++)
		nCk[i] = nCr(i,k);
}



signed main(){
	fastio
	
	cin >> n >> k >> q;

	int Q[q];

	//First, add the numbers of a val into cnt[i]
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		cnt[tmp]++;
	}
	for(int j = 0;j < q;j++){
		cin >> Q[j];
		has[Q[j]] = 1;
	}

	init();

	//Now, we find how many multiples a number has
	//The answer we would like to find is => nCr(cnt[i],k)
	//However, the gcd might not be i when we choose its multiples
	//The answer should be phi(i)*nCr(cnt[i],k)
	//(phi[i] => Euler Totient)
	for(int i = 1;i < N;i++){
		for(int j = i+i;j < N;j += i){
			cnt[i] += cnt[j];
		}
	}

	int sum = 0;
	for(int i = 1;i < N;i++){
		sum = (sum+phi[i]*nCk[cnt[i]]%MOD)%MOD;
	}

	for(auto x : Q){
		for(auto y : d[x]){
			sum = ((sum-phi[y]*nCk[cnt[y]]%MOD)%MOD+MOD)%MOD;
			cnt[y]++;
			sum = (sum+phi[y]*nCk[cnt[y]]%MOD)%MOD;
		}
		cout << sum << "\n";
	}
}