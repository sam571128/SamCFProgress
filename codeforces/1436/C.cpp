#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1005, MOD = 1e9+7;
int fact[N];
int cnt1, cnt2;

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
	for(int i = 1;i < N;i++)
		fact[i] = fact[i-1]*i%MOD;
}

int nPr(int n, int r){
	return (n < r ? 0 : fact[n]*fastpow(fact[n-r],MOD-2)%MOD);
}

void bs(int l, int r, int pos){
	int mid = l+r>>1;
	if(l==r) return;
	if(mid <= pos){
		if(mid < pos) cnt1++;
		bs(mid+1,r,pos);
	}else{
		cnt2++;
		bs(l,mid,pos);
	}
}


signed main(){
	fastio
	init();
	int n,x,pos;
	cin >> n >> x >> pos;
	bs(0,n,pos);
	cout << nPr(x-1,cnt1)*nPr(n-x,cnt2)%MOD*fact[n-cnt1-cnt2-1]%MOD << "\n";
}	