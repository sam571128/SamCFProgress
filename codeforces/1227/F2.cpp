#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int MOD = 998244353, N = 2e5+5;

int fact[N];
void init(){
	fact[0] = 1;
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n % MOD;
		n = n*n%MOD;
		p>>=1;
	}
	return res;
}

int nCr(int n, int r){
	if(n < r) return 0;
	return fact[n]*fastpow(fact[n-r],MOD-2)%MOD*fastpow(fact[r],MOD-2)%MOD;
}

signed main(){
	//fastio
	init();
	int n,k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin >> arr[i];
	}
	int cnt1 = 0, cnt2 = 0;
	//cnt1 is for arr[i]!=arr[i+1], cnt2 is for arr[i]==arr[i+1] 
	for(int i = 0;i < n;i++){
		if(arr[i]==arr[(i+1)%n]){
			cnt2++;
		}else{
			cnt1++;
		}
	}

	int sum = 0;
	//We need to try and find all situations so that a (+1) is greater than b (-1)
	//However, the possibilties for a > b is the same for b > a, so we could use (k^n - same)/2
	for(int i = 0;i <= cnt1/2;i++){
		sum = (sum + nCr(cnt1,i)*nCr(cnt1-i,i)%MOD*fastpow(k-2,cnt1-i-i)%MOD*fastpow(k,cnt2)%MOD)%MOD;
	}
	cout << (fastpow(k,n)%MOD-sum%MOD+MOD)%MOD*fastpow(2,MOD-2)%MOD << "\n";
}