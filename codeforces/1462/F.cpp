#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
map<int,int> m;

int bit[2][N];

void update(int idx,int pos, int val){
	if(pos==0) return;
	while(pos < N){
		bit[idx][pos] += val;
		pos += pos&-pos;
	}
}

int query(int idx, int pos){
	if(pos == 0) return 0;
	int res = 0;
	while(pos){
		res += bit[idx][pos];
		pos -= pos&-pos;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	vector<int> tt;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int l,r;
		cin >> l >> r;
		v.push_back({l,r});
		tt.push_back(l);
		tt.push_back(r);
	}
	sort(tt.begin(),tt.end());
	tt.resize(unique(tt.begin(),tt.end())-tt.begin());
	for(int i = 0;i < tt.size();i++){
		bit[0][i] = 0;
		bit[0][i+1] = 0;
		bit[1][i] = 0;
		bit[1][i+1] = 0;
		m[tt[i]] = i+1;
	}
	for(int i = 0;i < n;i++){
		update(0,m[v[i].first],1);
	}
	sort(v.begin(),v.end());
	int ma = 0;
	for(int i = 0;i < n;i++){
		update(0,m[v[i].first],-1);
		ma = max(query(1,tt.size())-query(1,m[v[i].first]-1)+query(0,m[v[i].second])-query(0,m[v[i].first]-1),ma);
		update(1,m[v[i].second],1);
	}
	cout << n-ma-1 << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}