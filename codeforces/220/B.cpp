#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

gp_hash_table<int,int> m;

const int N = 1e5+5;
int k, ans = 0;

struct query{
	int l, r, id;
	bool operator < (query b){
		return l/k == b.l/k ? r < b.r : l/k < b.l/k;
	}
};

void add(int n){
	if(m[n]==n) ans--;
	m[n]++;
	if(m[n]==n) ans++;
}

void del(int n){
	if(m[n]==n) ans--;
	m[n]--; 
	if(m[n]==n) ans++;
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	k = sqrt(n);
	int arr[n+1];
	for(int i = 1;i <= n;i++) cin >> arr[i];
	vector<query> Q;
	for(int i = 0;i < m;i++){
		int l, r;
		cin >> l >> r;
		Q.push_back({l,r,i});
	}
	sort(Q.begin(),Q.end());
	int res[m];
	int l = 1, r = 0, t = 0;
	for(auto [ql,qr,id] : Q){
		while(l < ql) del(arr[l++]);
		while(l > ql) add(arr[--l]);
		while(r < qr) add(arr[++r]);
		while(r > qr) del(arr[r--]);
		res[id] = ans;
	}
	for(auto x : res) cout << x << "\n";
}