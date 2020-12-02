#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

gp_hash_table<int,int> m;

const int N = 1e6+5;
int bit[N];

void modify(int pos, int val){
	while(pos < N){
		bit[pos] += val;
		pos += pos&-pos;
	}
}

int query(int pos){
	int res = 0;
	while(pos){
		res += bit[pos];
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	//fastio
	int n;
	cin >> n;
	vector<array<int,3>> v;
	vector<int> tmp;
	int l[n], r[n];
	for(int i = 0;i < n;i++){
		cin >> l[i] >> r[i];
		tmp.push_back(l[i]);
		tmp.push_back(r[i]);
		v.push_back({l[i],r[i],i});
	}
	sort(v.begin(),v.end());
	sort(tmp.begin(),tmp.end());
	tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
	for(int i = 0;i < tmp.size();i++){
		m[tmp[i]] = i+1; 
	}
	int ans[n];
	for(auto x : v){
		modify(m[x[1]],1);
	}
	for(auto x : v){
		ans[x[2]] = query(m[x[1]]);
		modify(m[x[1]],-1);
	}
	for(auto x : ans) cout << x-1 << "\n";
}