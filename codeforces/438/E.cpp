#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5, MOD = 998244353, G = 3;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n % MOD;
		n = n * n % MOD;
		p >>= 1;
	}
	return res;
}

struct NTT{
	int n, inv, rev[N];
	int omega[N], iomega[N];
	void init(int n_){
		n = 1;
		while(n <= n_) n<<=1;
		inv = fastpow(n,MOD-2);
		int k = __lg(n);
		int x = fastpow(G, (MOD-1)/n);
		omega[0] = 1;
		for(int i = 1;i < n;i++)
			omega[i] = omega[i-1] * x % MOD;
		iomega[n-1] = fastpow(omega[n-1],MOD-2);
		for(int i = n-2; i >= 0; i--)
			iomega[i] = iomega[i+1] * x % MOD;
		for(int i = 0;i < n;i++){
			int t = 0;
			for(int j = 0;j < k;j++)
				if(i&(1<<j)) t |= (1<<k-j-1);
			rev[i] = t;
		}
	}
	void transform(int *a, int *xomega){
		for(int i = 0;i < n;i++)
			if(i < rev[i]) swap(a[i],a[rev[i]]);
		for(int len = 2;len <= n;len <<= 1){
			int mid = len>>1;
			int r = n/len;
			for(int j = 0;j < n;j += len){
				for(int i = 0;i < mid;i++){
					int tmp = xomega[r*i] * a[j+mid+i] % MOD;
					a[j+mid+i] = (a[j+i] - tmp + MOD) % MOD;
					a[j+i] = (a[j+i]+tmp)%MOD;
				}
			}
		}
	}
	void dft(int *a){transform(a,omega);}
	void idft(int *a){transform(a,iomega); for(int i = 0;i < n;i++) a[i] = a[i]*inv %MOD;}

	int x[N], y[N], z[N];

	void copy_(int *a, int *b, int m){
		for(int i = 0;i < m;i++)
			a[i] = b[i];
		for(int i = m;i < n;i++)
			a[i] = 0;
	}

	void copy(int *a, int *b, int m){
		for(int i = 0;i < m;i++)
			a[i] = b[i];
	}

	//B_{k+1} = B_k(2-AB_k) (mod MOD)
	void inverse(int *a, int *b, int m){
		if(m==1){
			b[0] = fastpow(a[0],MOD-2);
			return;
		}
		inverse(a,b,m>>1);
		init(m<<1);
		copy_(x,a,m); copy_(y,b,m>>1);
		dft(x); dft(y);
		for(int i = 0;i < n;i++) x[i] = y[i]*(2-x[i]*y[i]%MOD+MOD)%MOD;
		idft(x);
		copy(b,x,m);
	}

	int c[N], d[N];
	//Q_{k+1} = pow(2,MOD-2)(Q_k + P*pow(Q_k,MOD-2)) (mod MOD)
	void sqrt(int *a, int *b, int m){
		if(m==1){
			b[0] = 1;
			return;
		}
		sqrt(a,b,m>>1);
		for(int i = m;i < m<<1;i++)
			b[i] = 0;
		inverse(b,d,m);
		init(m<<1);
		for(int i = m;i < m<<1;i++)
			b[i] = d[i] = 0;
		int inv2 = fastpow(2,MOD-2);
		copy_(x,a,m);
		dft(x); dft(d);
		for(int i = 0;i < n;i++)
			x[i] = x[i]*d[i]%MOD;
		idft(x);
		for(int i = 0;i < m;i++)
			b[i] = (b[i]+x[i])%MOD*inv2%MOD;
	}
} NTT;

int ans[N], c[N], tt[N];

//DP[x] = \Sum_{c} (\Sum_{i}(DP[i]*DP[x-c-i]))
//F[x] = C[x] * F[x] * F[x] + F[0]
//F[0] = 1
//C[x]*F[x]^2 - F[x] +1 = 0;
// F[x] = -2+\sqrt(1-4C[x])/2C[x] = 2/(1+\sqrt(1-4C[x]))

signed main(){
	fastio
	int n,m;
    cin >> n >> m;
    for(int i = 0, tmp;i < n;i++){
    	cin >> tmp;
    	c[tmp]=-4;
    }
    int k = 1;
    while(k <= m) k <<= 1;
    c[0] = (c[0]+1)%MOD;
    NTT.sqrt(c,tt,k);
    tt[0] = (tt[0]+1)%MOD;
    NTT.inverse(tt,ans,k);
    for(int i = 1;i <= m;i++){
    	cout << ans[i]*2%MOD << "\n";
    }
}