#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5, lg = 20, MOD = 1e9+7;

struct query{
	int x, id;
	query(int x, int id): x(x), id(id){}
};

struct linear_basis{
	int base[lg], sz = 0;
	void insert(int mask){
		for(int i = 0;i < lg;i++){
			if((mask&1<<i)==0) continue;
			if(!base[i]){
				base[i] = mask;
				sz++;
				return;
			}
			mask ^= base[i];
		}
	}
	bool check(int mask){
		for(int i = 0;i < lg;i++){
			if((mask&1<<i)==0) continue;
			if(!base[i]) return false;
			mask ^= base[i];
		}
		return true;
	}
} lb;

int fastpow(int n, int p){
	int res = 1;
	while(p){
		if(p&1) res = res * n % MOD;
		n = n * n % MOD;
		p>>=1;
	}
	return res;
}

vector<query> pos[N];

signed main(){
	fastio
	int n, q;
	cin >> n >> q;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < q;i++){
		int l,x;
		cin >> l >> x;
		l--;
		pos[l].push_back({x,i});
	}
	int ans[q] = {};
	for(int i = 0;i < n;i++){
		lb.insert(arr[i]);
		for(auto [x,j] : pos[i]){
			if(lb.check(x)){
				ans[j] = fastpow(2,i+1-lb.sz);
			}
		}
	}
	for(auto x : ans) cout << x << "\n";
}