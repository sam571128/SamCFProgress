#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
vector<int> lpf(N,1);
vector<int> primes;
void init(){
	for(int i = 2;i < N;i++){
		if(lpf[i]==1){
			lpf[i] = i;
			primes.push_back(i);
		}
		for(int x : primes){
			if(x*i > N) break;
			lpf[x*i]=x;
			if(x==lpf[i]) break;
		}
	}
}

void solve(){
	int n;
	cin >> n;
	map<vector<int>,int> m;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		vector<int> v;
		while(tmp!=1){
			int cnt = 0, now = lpf[tmp];
			while(tmp%now==0) tmp/=now, cnt++;
			if(cnt&1) v.push_back(now);
		}
		m[v]++;
	}
	int ans0 = 0, ans1 = 0;
	for(auto [a,b] : m){
		//cout << b << "\n";
		ans0 = max(b,ans0);
		if(a.size()==0||b%2==0){
			ans1 += b;
		}
	}
	int q;
	cin >> q;
	while(q--){
		int x;
		cin >> x;
		if(x == 0) cout << ans0 << "\n";
		else cout << max(ans0,ans1) << "\n";
	}
}

signed main(){
	fastio
	init();
	int t;
	cin >> t;
	while(t--) solve();
}