#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int m[(int)1e6+5];

const int N = 2e5+5;
ll k, ans = 0;

struct query{
	int l, r, id;
	bool operator < (query b){
		return l/k == b.l/k ? r < b.r : l/k < b.l/k;
	}
};

void add(int n){
	ans -= (ll)m[n]*m[n]*n;
	m[n]++;
	ans += (ll)m[n]*m[n]*n;
}

void del(int n){
	ans -= (ll)m[n]*m[n]*n;
	m[n]--;
	ans += (ll)m[n]*m[n]*n;
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
	ll res[m];
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