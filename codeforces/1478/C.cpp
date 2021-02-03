#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,int> m;
	for(int i = 0;i < 2*n;i++){
		int tmp;
		cin >> tmp;
		m[tmp]++;
	}
	vector<int> v;
	bool ok = true;
	for(auto [a,b] : m){
		v.push_back(a);
		if(b != 2) ok = false;
	}
	int sum = 0;
	vector<int> tt;
	for(int i = 1;i < v.size();i++){
		if((v[i]-v[i-1])%(2*i)) ok = false;
		tt.push_back((v[i]-v[i-1])/(2*i));
	}
	for(int i = 0;i < tt.size();i++) sum += (tt.size()-i)*tt[i];
	if(v[0] - 2*sum <= 0) ok = false;
	if((v[0]-2*sum)%(2*v.size())) ok = false;
	cout << (ok ? "YES\n" : "NO\n");
}

signed main(){
	//fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}