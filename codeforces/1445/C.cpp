#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = (res * n);
		n = (n * n);
		p>>=1;
	}
	return res;
}

void solve(){
	map<int,int> fac;
	int n,m;
	cin >> n >> m;
	if(n%m){
		cout << n << "\n";
		return;
	}
	int tmp = m;
	fac[m]++;
	for(int i = 2;i <= sqrt(tmp);i++){
		while(m%i==0){
			fac[i]++;
			m/=i;
		}
	}
	if(m!=tmp)fac[m]++;
	int ans = 1;
	for(auto [a,b] : fac){
		tmp = n;
		if(fastpow(a,b)==1) continue;
		while(tmp%fastpow(a,b)==0){
			tmp/=a;
		}
		if(tmp==n) continue;
		ans = max(tmp,ans);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}