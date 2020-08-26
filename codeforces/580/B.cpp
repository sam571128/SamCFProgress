#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <bits/stdc++.h>
#include <bits/extc++.h>


using namespace std;
using namespace __gnu_pbds;

#define int long long
#define rep(x,m,n) for(int x = m; x < n;x++)
#define repp(x,m,n) for(int x = m; x <= n;x++)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update, ordered_set>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//find_by_order(), order_of_key();
#define MOD 1000000007
void solve();


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
	int t = 1;
	//cin >> t;
	rep(i,0,t) solve();
}

void solve(){
	int n,d;
	cin >> n >> d;
	vector<pair<int,int>> v;
	for(int i = 0; i < n;i++){
		int m,s;
		cin >> m >> s;
		v.emplace_back(m,s);
	}	
	sort(v.begin(),v.end());
	int pref[v.size()+2];
	int arr[v.size()];
	pref[0] = 0;
	for(int i = 0; i < v.size();i++){
		//cout << v[i].first << " " << pref[i] << "\n";
		pref[i+1] = v[i].second + pref[i];
		arr[i] = v[i].first;
	}
	pref[v.size()+1] = pref[v.size()];
	int ans = 0;// tmp = v[0].second, mn = v[0].first;
	for(int i = 0;i < v.size();i++){
		int idx = (lower_bound(arr,arr+v.size(),v[i].first+d)-1-arr);
		//cout << i << " " << idx << "\n";
		//cout << pref[idx+1] << " " << pref[i] << "\n";
		ans = max(ans, pref[idx+1]-pref[i]);
	}
	cout <<  ans << "\n";
	//for(auto x : pref) cout << x << " ";
}